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

  LogChoice::LogChoice(const LogBrancher& b, const std::vector<C>& children)
    : Choice(b,children.size()) {
    cs = heap.alloc<C>(children.size());
    for (unsigned int i=0; i<children.size(); i++)
      cs[i] = children[i];
  }

  namespace {

    /// surrounds `symbols` with whitespaces; returns `true` if a match found
    bool surround_two_symbols(string& str, string symbols) {
      bool found = false;
      size_t start = 0;
      size_t pos = str.find(symbols);

      if (pos != string::npos) {
        found = true;
      }

      while (pos != string::npos) {
        size_t next;
        if (str.at(pos - 1) == ' ' && str.at(pos + 2) == ' ') {
          // next = pos + 1;
          next = pos;
        } else {
          str = str.substr(0, pos) + " " + symbols + " " + str.substr(pos + 2);
          std::cerr << "replaced " << symbols << ": " << str << "\n";
          next = pos + 2;
        }
        std::cerr << "next: " << next << "\n";
        pos = str.find(symbols, next + 1); // advance due to whitespace added
      }

      return found;
    }

    /// replace '==' with '='
    void double_to_single(string& str) {
      size_t start = 0;
      size_t pos = str.find('==');

      while (pos != string::npos) {
        str = str.substr(0, pos) + "=" + str.substr(pos + 2);
        pos = str.find("==", pos); // advance due to whitespace added
      }
    }

    string pre_process(const string& source) {
        string result = source;

        bool complex_equals = false;
        bool double_equals = false;

        /// surround != with whitespaces
        complex_equals |= surround_two_symbols(result, "!=");
        complex_equals |= surround_two_symbols(result, ">=");
        complex_equals |= surround_two_symbols(result, "<=");

        double_equals |= surround_two_symbols(result, "==");

        if (double_equals) {
          double_to_single(result);
        }

        /// surround = with whitespaces

        if (!double_equals) {
          size_t start = 0;
          size_t pos = result.find("=");
          while (pos != string::npos) {
            size_t next;
            if ((result.at(pos - 1) == ' ' && result.at(pos + 1) == ' ') ||
              (result.at(pos - 1) == '!') || (result.at(pos - 1) == '<') ||
              (result.at(pos - 1) == '>')) {
              next += 1;
            } else {
              result = result.substr(0, pos) + " = " + result.substr(pos + 1);
              next += 2;
            }
          pos = result.find("=", next); // advance due to whitespace added
          }
        }

        return result;
    }

    LogChoice* parseChoice(const LogBrancher& b, const FlatZincSpace& s, int nChildren, const string& raw_line, int* retry) {
      std::string line = pre_process(raw_line);
      std::cout << "<> <> <> parsing choice: " << line << "\n";
      if (nChildren==0)
        return NULL;
      size_t space = line.find(" ");
      space = line.find(" ",space+1);
      std::vector<LogChoice::C> children;
      
      // b.symbols.exec<PS>();
            
      for (int i=0; i<nChildren;i++) {
        size_t next_space = line.find(" ",space+1);
        if (next_space == string::npos) {
          std::cerr << "npos\n";
          next_space = line.size() - 1;
          // line += " ";
        }
        stringstream nid_s(line.substr(space+1, next_space-space-1));
        int n_id;
        nid_s >> n_id;
        std::cerr << ">>> n_id: " << n_id << "\n";
        space = next_space;
        next_space = line.find(" ",space+1);
        string var = line.substr(space+1, next_space-space-1);
        
        int var_idx;
        size_t bracket = var.find("[");
        if (bracket!=string::npos) {
          string basevar = var.substr(0,bracket);
          string array_idx_s = var.substr(bracket+1,var.size()-bracket-2);
          stringstream aidx(array_idx_s);
          int array_idx;
          aidx >> array_idx;
          SymbolEntry se;
          if (b.symbols.get(basevar,se)) {
            var_idx = b.arrays[se.i + array_idx];
          } else {
            std::cerr << "return NULL: 1\n";
            return NULL;
          }
        } else {        
          SymbolEntry se;
          std::cout << "var:|" << var << "|\n";
          if (b.symbols.get(var,se)) {
            assert(se.t==ST_INTVAR);
            var_idx = se.i;
          } else if (var == "") {
            std::cout << "no decision\n";
            children.push_back(LogChoice::C(n_id));
            space = next_space;
            next_space = line.find(" ",space+1);
            continue;
          } else {
            std::cerr << "return NULL: 2, not found: " << var << std::endl;
            return NULL;
          }
        }
        
        space = next_space;
        next_space = line.find(" ",space+1);
        string op = line.substr(space+1, next_space-space-1);
        IntRelType irt;
        if (op=="=")
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
        space = next_space;
        next_space = line.find(" ",space+1);
        stringstream val_s(line.substr(space+1, next_space-space-1));
        int val;
        val_s >> val;
        space = next_space;
        string label = var+" "+op+" "+val_s.str();
        bool thisChoiceImplied = false;
        switch (irt) {
          case IRT_EQ:
            if (s.iv[var_idx].assigned()) {
              if (s.iv[var_idx].val()==val) thisChoiceImplied = true;
              label = string("[")+(s.iv[var_idx].val()==val ? "i":"f")+"] "+label;
            } else if (!s.iv[var_idx].in(val)) {
              label = string("[f] ")+label;
            }
            break;
          case IRT_NQ:
            if (s.iv[var_idx].assigned()) {
              if (s.iv[var_idx].val()!=val) thisChoiceImplied = true;
              label = string("[")+(s.iv[var_idx].val()!=val ? "i":"f")+"] "+label;
            } else if (!s.iv[var_idx].in(val)) {
              thisChoiceImplied = true;
              label = string("[i] ")+label;
            }
            break;
          case IRT_LQ:
            if (s.iv[var_idx].max() <= val) {
              thisChoiceImplied = true;
              label = string("[i] ")+label;
            }
            else if (s.iv[var_idx].min() > val)
              label = string("[f] ")+label;
            break;
          case IRT_LE:
            if (s.iv[var_idx].max() < val) {
              thisChoiceImplied = true;
              label = string("[i] ")+label;
            }
            else if (s.iv[var_idx].min() >= val)
              label = string("[f] ")+label;
            break;
          case IRT_GR:
            if (s.iv[var_idx].min() > val) {
              thisChoiceImplied = true;
              label = string("[i] ")+label;
            }
            else if (s.iv[var_idx].max() <= val)
              label = string("[f] ")+label;
            break;
          case IRT_GQ:
            if (s.iv[var_idx].min() >= val) {
              thisChoiceImplied = true;
              label = string("[i] ")+label;
            }
            else if (s.iv[var_idx].max() < val)
              label = string("[f] ")+label;
            break;
        }
        // if (b.omitImplied && thisChoiceImplied) {
        //   *retry = n_id;
        //   std::cerr << "return NULL: 3\n";
        //   return NULL;
        // }
        children.push_back(LogChoice::C(n_id,var_idx,irt,val,label));
      }
      std::cerr << "successfully return log choice\n";
      return new LogChoice(b,children);
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
    std::cerr << "LogBrancher::status\n";
    const FlatZincSpace& s = static_cast<const FlatZincSpace&>(home);
    if (cur_choice)
      return true;
    while (log.good()) {
      string str_line;
      getline(log, str_line);
      // std::cerr << "parsing: " << str_line << std::endl;
      int nodeNumber, nChildren;
      parseNode(str_line, nodeNumber, nChildren);
      std::cerr << "cur_node: " << cur_node << " nodeNumber: " << nodeNumber << " (at logbrancher.cpp:240)\n";
      if (nodeNumber==cur_node) {
        int retry = -1;
        cur_choice = parseChoice(*this,s,nChildren,str_line,&retry);
        if (retry != -1) {
          cur_node = retry;
          continue;
        }
        return cur_choice!=NULL;
      }
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
    std::cerr << "LogBrancher::commit\n";
    const LogChoice& lc = static_cast<const LogChoice&>(c);
    // std::cerr << "curr_node old: " << cur_node << " curr_node new: " << lcc.n << "\n";
    const LogChoice::C& lcc = lc.cs[a];
  
    if (lc.cs->empty) {
      std::cerr << "empty decision\n";
      return ES_OK;
    }
    if (cur_choice && cur_choice->cs[a].n == lcc.n) {
      cur_choice = NULL;
    }

    std::cerr << "[cur_node] old: " << cur_node << " new: " << lcc.n << "\n";

    cur_node = lcc.n;

    if (lc.cs->skip) {
      std::cerr << "skip this node\n";
      return ES_OK;
    }

    FlatZincSpace& s = static_cast<FlatZincSpace&>(home);
    rel(s, s.iv[lcc.pos], lcc.irt, lcc.val);
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
