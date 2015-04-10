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

    LogChoice* parseChoice(const LogBrancher& b, const FlatZincSpace& s, int nChildren, const string& line) {
      if (nChildren==0)
        return NULL;
      size_t space = line.find(" ");
      space = line.find(" ",space+1);
      std::vector<LogChoice::C> children;
      
      // b.symbols.exec<PS>();
            
      for (int i=0; i<nChildren;i++) {
        size_t next_space = line.find(" ",space+1);
        stringstream nid_s(line.substr(space+1, next_space-space-1));
        int n_id;
        nid_s >> n_id;
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
            return NULL;
          }
        } else {        
          SymbolEntry se;
          if (b.symbols.get(var,se)) {
            assert(se.t==ST_INTVAR);
            var_idx = se.i;
          } else {
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
        else GECODE_NEVER;
        space = next_space;
        next_space = line.find(" ",space+1);
        stringstream val_s(line.substr(space+1, next_space-space-1));
        int val;
        val_s >> val;
        space = next_space;
        string label = var+" "+op+" "+val_s.str();
        switch (irt) {
          case IRT_EQ:
            if (s.iv[var_idx].assigned()) {
              label = string("[")+(s.iv[var_idx].val()==val ? "i":"f")+"] "+label;
            } else if (!s.iv[var_idx].in(val)) {
              label = string("[f] ")+label;
            }
            break;
          case IRT_NQ:
            if (s.iv[var_idx].assigned()) {
              label = string("[")+(s.iv[var_idx].val()!=val ? "i":"f")+"] "+label;
            } else if (!s.iv[var_idx].in(val)) {
              label = string("[i] ")+label;
            }
            break;
          case IRT_LQ:
            if (s.iv[var_idx].max() <= val)
              label = string("[i] ")+label;
            else if (s.iv[var_idx].min() > val)
              label = string("[f] ")+label;
            break;
          case IRT_LE:
            if (s.iv[var_idx].max() < val)
              label = string("[i] ")+label;
            else if (s.iv[var_idx].min() >= val)
              label = string("[f] ")+label;
            break;
          case IRT_GR:
            if (s.iv[var_idx].min() > val)
              label = string("[i] ")+label;
            else if (s.iv[var_idx].max() <= val)
              label = string("[f] ")+label;
            break;
          case IRT_GQ:
            if (s.iv[var_idx].min() >= val)
              label = string("[i] ")+label;
            else if (s.iv[var_idx].max() < val)
              label = string("[f] ")+label;
            break;
        }
        children.push_back(LogChoice::C(n_id,var_idx,irt,val,label));
      }
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
    : Brancher(home,share,b), log(b.log), symbols(b.symbols), arrays(b.arrays), cur_choice(NULL), cur_node(b.cur_node) {
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
    if (cur_choice)
      return true;
    while (log.good()) {
      char line[1024];
      log.getline(line,sizeof(line));
      int nodeNumber, nChildren;
      parseNode(line, nodeNumber, nChildren);
      if (nodeNumber==cur_node) {
        cur_choice = parseChoice(*this,s,nChildren,line);
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
    const LogChoice& lc = static_cast<const LogChoice&>(c);
    const LogChoice::C& lcc = lc.cs[a];
    cur_node = lcc.n;
    if (cur_choice && cur_choice->cs[a].n == lcc.n)
      cur_choice = NULL;
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

  void branch(Home home, SymbolTable<SymbolEntry>& symbols, vector<int>& arrays, std::istream& log) {
    if (home.failed()) return;
    LogBrancher::post(home,symbols,arrays,log);
  }


}}
