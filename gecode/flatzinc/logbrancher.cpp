#include <gecode/flatzinc.hh>
#include <gecode/flatzinc/logbrancher.hh>

#include <strstream>

using namespace std;

namespace Gecode { namespace FlatZinc {

  struct PS {
    static void e(const string& s, const FlatZinc::SymbolEntry& se) {
      std::cerr << "found " << s << "\n";
    }
  };

  LogChoice::LogChoice(const LogBrancher& b, const std::vector<C>& children,
                       bool stop_marker)
      : Choice(b, children.size()), stop_marker(stop_marker) {
    cs = heap.alloc<C>(static_cast<int>(children.size()));
    for (unsigned int i=0; i<children.size(); i++)
      cs[i] = children[i];
  }

  namespace {

    /// surrounds `symbols` with whitespaces; returns `true` if a match found
    bool surround_two_symbols(string& str, string symbols) {
      bool found = false;
      size_t pos = str.find(symbols);

      if (pos != string::npos) {
        found = true;
      }

      auto sym_len = symbols.size();

      while (pos != string::npos) {
        size_t next;
        if (str.at(pos - 1) == ' ' && str.at(pos + sym_len) == ' ') {
          // next = pos + 1;
          next = pos;
        } else {
          str = str.substr(0, pos) + " " + symbols + " " + str.substr(pos + sym_len);
          next = pos + sym_len;
        }
        pos = str.find(symbols, next + 1); // advance due to whitespace added
      }

      return found;
    }

    void surround_single(string& str, string symbol) {
      size_t pos = str.find(symbol);
      while (pos != string::npos) {
        size_t next;
        if (
          (str.at(pos - 1) == ' ' && str.at(pos + 1) == ' ') ||
          (str.at(pos - 1) == '!') || (str.at(pos - 1) == '<') ||
          (str.at(pos - 1) == '>') || (str.at(pos - 1) == '=') ||
          (str.at(pos + 1) == '=')
          ) {
          next = pos;
        } else {
          str = str.substr(0, pos) + " " + symbol + " " + str.substr(pos + 1);
          next = pos + 2;
        }
      pos = str.find(symbol, next + 1); // advance due to whitespace added
      }
    }

    /// replace '==' with '='
    void double_to_single(string& str) {
      size_t pos = str.find("==");

      while (pos != string::npos) {
        str = str.substr(0, pos) + "=" + str.substr(pos + 2);
        pos = str.find("==", pos); // advance due to whitespace added
      }
    }

    string pre_process(const string& source) {
        string result = source;

        bool complex_equals = false;
        bool double_equals = false;

        double_equals |= surround_two_symbols(result, "==");

        if (double_equals) {
          double_to_single(result);
        }

        /// surround != with whitespaces
        complex_equals |= surround_two_symbols(result, "!=");
        complex_equals |= surround_two_symbols(result, ">=");
        complex_equals |= surround_two_symbols(result, "<=");

        /// surround = with whitespaces

        // surround_two_symbols(result, "<");
        // surround_two_symbols(result, ">");

        surround_single(result, "=");
        surround_single(result, "<");
        surround_single(result, ">");

        return result;
    }

    vector<string> split(const string& line, string del) {
      vector<string> res;

      size_t prev = 0;

      auto pos = line.find(del, 0);

      while (pos != string::npos) {
        auto str = line.substr(prev, pos - prev);
        if (str.size() > 0) {
          res.push_back(str);
        }
        prev = pos + 1;

        pos = line.find(del, prev);
      }

      if (prev < line.size()) {
        auto str = line.substr(prev, line.size() - prev);
        if (str.size() > 0) {
          res.push_back(str);
        }
      }

      return res;
    }


    /// returns var_idx or aborts
    int find_var(const LogBrancher& b, string var_str) {

      auto bracket = var_str.find("[");

      if (bracket != string::npos) {
        string basevar = var_str.substr(0, bracket);
        int array_idx = stoi(var_str.substr(bracket+1, var_str.size() - bracket-2));

        SymbolEntry se;
        if (b.symbols.get(basevar, se)) {
          return b.arrays[se.i + array_idx];
        } else {
          std::cerr << "reading `var[id]`, `var` is not found\n";
        }
      } else {
        SymbolEntry se;
        if (b.symbols.get(var_str, se)) {
          return se.i;
        } else if (var_str == "") {
          std::cerr << "var is empty: ``\n";
        } else {
          std::cerr << "reading `var`, `var` is not found\n";
        }

      }
      assert(false);
      return -1;
    }



    IntRelType parse_operator(string op) {
      IntRelType irt;
      if (op=="=" || op == "==")
        irt = IRT_EQ;
      else if (op=="!=")
        irt = IRT_NQ;
      else if (op=="<")
        irt = IRT_LE;
      else if (op=="<=")
        irt = IRT_LQ;
      else if (op==">")
        irt = IRT_GR;
      else if (op==">=")
        irt = IRT_GQ;
      else {
        irt = IRT_EQ; // silence "uninitialized" warning
        GECODE_NEVER;
      }

      return irt;
    }

    bool processImpliedBool(const FlatZincSpace& space, IntRelType irt,
                        string& label, int var_idx, int val) {
      bool choiceImplied = false;

      switch(irt) {
        case IRT_EQ:
          if (space.bv[var_idx].assigned()) {
            if (space.bv[var_idx].val() == val) {
              label = string("[")+(space.bv[var_idx].val()==val ? "i":"f")+"] "+label;
              choiceImplied = true;
            } else if (!space.bv[var_idx].in(val)) {
              label = string("[f] ")+label;
            }
          }
        break;
        case IRT_NQ:
          if (space.bv[var_idx].assigned()) {
            if (space.bv[var_idx].val()!=val) choiceImplied = true;
            label = string("[")+(space.bv[var_idx].val()!=val ? "i":"f")+"] "+label;
          } else if (!space.bv[var_idx].in(val)) {
            choiceImplied = true;
            label = string("[i] ")+label;
          }
          break;
      }
      return choiceImplied;
    }

    bool processImplied(const FlatZincSpace& space, IntRelType irt,
                        string& label, int var_idx, int val) {
      bool choiceImplied = false;
      switch (irt) {
        case IRT_EQ:
          if (space.iv[var_idx].assigned()) {
            if (space.iv[var_idx].val()==val) choiceImplied = true;
            label = string("[")+(space.iv[var_idx].val()==val ? "i":"f")+"] "+label;
          } else if (!space.iv[var_idx].in(val)) {
            label = string("[f] ")+label;
          }
          break;
        case IRT_NQ:
          if (space.iv[var_idx].assigned()) {
            if (space.iv[var_idx].val()!=val) choiceImplied = true;
            label = string("[")+(space.iv[var_idx].val()!=val ? "i":"f")+"] "+label;
          } else if (!space.iv[var_idx].in(val)) {
            choiceImplied = true;
            label = string("[i] ")+label;
          }
          break;
        case IRT_LQ:
          if (space.iv[var_idx].max() <= val) {
            choiceImplied = true;
            label = string("[i] ")+label;
          }
          else if (space.iv[var_idx].min() > val)
            label = string("[f] ")+label;
          break;
        case IRT_LE:
          if (space.iv[var_idx].max() < val) {
            choiceImplied = true;
            label = string("[i] ")+label;
          }
          else if (space.iv[var_idx].min() >= val)
            label = string("[f] ")+label;
          break;
        case IRT_GR:
          if (space.iv[var_idx].min() > val) {
            choiceImplied = true;
            label = string("[i] ")+label;
          }
          else if (space.iv[var_idx].max() <= val)
            label = string("[f] ")+label;
          break;
        case IRT_GQ:
          if (space.iv[var_idx].min() >= val) {
            choiceImplied = true;
            label = string("[i] ")+label;
          }
          else if (space.iv[var_idx].max() < val)
            label = string("[f] ")+label;
          break;
      }

      return choiceImplied;
    }

    LogChoice* parseChoice(const LogBrancher& lb,
                            const FlatZincSpace& space, int nChildren,
                            const string& raw_line, int* retry) {

      std::string line = pre_process(raw_line);
      // std::cout << "<> <> <> parsing choice: " << line << "\n";

      const vector<string>& tokens = split(line, " ");

      bool stop_marker = false;

      if (nChildren == 0) {

        if (tokens.back() == "stop") {
        /// tell Gecode to abandon current branch
          stop_marker = true;
        } else {
          return NULL;
        }
      }

      vector<LogChoice::C> children;

      if (stop_marker) {
        /// NOTE(maxim): add a dummy child
        children.push_back(LogChoice::C(-1));
      }


      auto token_id = 2u;

      for (auto i = 0u; i < nChildren; ++i) {
        int n_id = stoi(tokens[token_id++]);

        if (token_id < tokens.size()) {
          string var_str = tokens[token_id];

          int first = var_str[0];

          /// a number, can't be a variable
          if (48 <= first && first <= 57) {
            children.push_back(LogChoice::C(n_id));
            continue;
          } else {
            token_id++;
          }

          int var_idx = find_var(lb, var_str);

          string op = tokens[token_id++];
          IntRelType irt = parse_operator(op);

          string val_s = tokens[token_id++];

          int val;
          LogChoice::VarType var_type;
          if (val_s == "true") {
            var_type = LogChoice::VarType::BOOL;
            val = 1;
          } else if (val_s == "false") {
            var_type = LogChoice::VarType::BOOL;
            val = 0;
          } else {
            var_type = LogChoice::VarType::INT;
            val = stoi(val_s);
          }

          string label = var_str + " " + op + " " + val_s;

          // std::cerr << label << "\n";

          /// TODO(maxim): make this work with BOOL variables

          bool choiceImplied = false;

          if (var_type == LogChoice::VarType::BOOL) {
            choiceImplied = processImpliedBool(space, irt, label, var_idx, val);
          } else if (var_type == LogChoice::VarType::INT) {
            choiceImplied = processImplied(space, irt, label, var_idx, val);
          }

          if (lb.omitImplied && choiceImplied) {
            *retry = n_id;
            std::cerr << "-----> IMPLIED CHOICE\n";
            return NULL;
          }


          children.push_back(LogChoice::C(n_id, var_idx, irt, val, label, var_type));

        } else {
          std::cerr << "no var...\n";
          token_id += 1;

          children.push_back(LogChoice::C(n_id));
        }
      }

      return new LogChoice(lb, children, stop_marker);
    }
    
    void parseNode(const std::string& line, int& nodeNumber, int& nChildren) {
        size_t space = line.find(" ");
        space = line.find(" ",space+1);
        stringstream sstr(line.substr(0,space));
        sstr >> nodeNumber >> nChildren;
    }
  }

  LogBrancher::LogBrancher(Space& home, bool share, LogBrancher& b)
    : Brancher(home,share,b), log(b.log), omitImplied(b.omitImplied), symbols(b.symbols), arrays(b.arrays), cur_choice(NULL), cur_node(b.cur_node) {
    if (b.cur_choice) {
      std::vector<LogChoice::C> cs(b.cur_choice->alternatives());
      for (unsigned int i=0; i<cs.size(); i++) {
        cs[i] = b.cur_choice->cs[i];
      }
      cur_choice = new LogChoice(*this,cs);
    }
  }

  bool
  LogBrancher::status(const Space& home) const {
    const FlatZincSpace& s = static_cast<const FlatZincSpace&>(home);

    if (s.iv.assigned() && s.bv.assigned()) {
      std::cout << "assigned\n";
      return false;
    }

    if (cur_choice)
      return true;
    while (log.good()) {
      string str_line;
      getline(log, str_line);
      // std::cerr << "parsing: " << str_line << std::endl;
      int nodeNumber, nChildren;
      parseNode(str_line, nodeNumber, nChildren);

      // some entries will be ingored, because cur_node is expected next
      if (nodeNumber != cur_node) continue;

      int retry = -1;
      cur_choice = parseChoice(*this, s, nChildren, str_line, &retry);
      if (retry != -1) {
        cur_node = retry;
        continue;
      }

      if (cur_choice == nullptr) {
        std::cerr << "no cur_choice\n";
      }

      return cur_choice!=NULL;
    }
    GECODE_NEVER;
    return false;
  }

  Choice*
  LogBrancher::choice(Space& home) {
    Choice* ret = cur_choice;
    cur_choice = NULL;
    return ret;
  }

  ExecStatus
  LogBrancher::commit(Space& home, const Choice& c, unsigned int a) {
    const LogChoice& lc = static_cast<const LogChoice&>(c);
    const LogChoice::C& lcc = lc.cs[a];

    if (lc.stop_marker) {
      return ES_FAILED;
    }
  
    if (lcc.empty) {

      return ES_OK;
    }
    if (cur_choice && cur_choice->cs[a].n == lcc.n) {
      cur_choice = NULL;
    }


    cur_node = lcc.n;

    if (lcc.skip) {

      return ES_OK;
    }

    FlatZincSpace& s = static_cast<FlatZincSpace&>(home);

    if (lcc.var_type == LogChoice::VarType::INT) {
      Gecode::rel(s, s.iv[lcc.pos], lcc.irt, lcc.val);
    } else if (lcc.var_type == LogChoice::VarType::BOOL) {
      Gecode::rel(s, s.bv[lcc.pos], lcc.irt, lcc.val);
    } else {
      assert(false);
    }
    return s.failed() ? ES_FAILED : ES_OK;
  }

  void
  LogBrancher::print(const Space& home, const Choice& c, unsigned int a,
                     std::ostream& o) const {
    const LogChoice& lc = static_cast<const LogChoice&>(c);
    o << lc.cs[a].label;
  }

  void branch(Home home, SymbolTable<SymbolEntry>& symbols, vector<int>& arrays,
              std::istream& log, bool omitImplied) {
    if (home.failed()) return;
    LogBrancher::post(home, symbols, arrays, log, omitImplied);
  }
}}
