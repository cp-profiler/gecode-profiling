#include <gecode/kernel.hh>
#include <gecode/flatzinc.hh>
#include <iostream>

namespace Gecode { namespace FlatZinc {
  
  class LogBrancher;
  
  class LogChoice : public Choice {
  public:
    struct C {
      int n;          // child number
      int pos;        // variable idx
      IntRelType irt; // operator
      int val;        // value
      std::string label;   // original label
      C(void) {}
      C(int n0, int pos0, IntRelType irt0, int val0, std::string label0)
        : n(n0), pos(pos0), irt(irt0), val(val0), label(label0) {}
    };
    C* cs;
    LogChoice(const LogBrancher& b, const std::vector<C>& children);

    virtual size_t size(void) const {
      return sizeof(LogChoice)+alternatives()*sizeof(C);
    }
    virtual void archive(Archive&) const {
      GECODE_NEVER;
    }
    void dump(void) const {
      for (unsigned int i=0; i<alternatives(); i++) {
        std::cerr << i << ": " << cs[i].n << " " << cs[i].pos << " "
          << cs[i].irt << " " << cs[i].val << "\n";
      }
      std::cerr << "----\n";
    }
  };
  
  class LogBrancher : public Brancher {
  public:
    std::istream& log;
    SymbolTable<SymbolEntry>& symbols;
    std::vector<int>& arrays;
    mutable LogChoice* cur_choice;
    int cur_node;

    LogBrancher(Home home, SymbolTable<SymbolEntry>& symbols0, std::vector<int>& arrays0, std::istream& log0)
      : Brancher(home), log(log0), symbols(symbols0), arrays(arrays0), cur_choice(NULL), cur_node(0) {}
    static void post(Home home, SymbolTable<SymbolEntry>& symbols, std::vector<int>& arrays, std::istream& log) {
      (void) new (home) LogBrancher(home,symbols,arrays,log);
    }
    
    virtual Choice* choice(Space& home);
    virtual Choice* choice(const Space&, Archive&) {
      GECODE_NEVER;
      return NULL;
    }
    
    virtual ExecStatus commit(Space& home, const Choice& c, unsigned int a);
    
    LogBrancher(Space& home, bool share, LogBrancher& b);

    virtual Brancher* copy(Space& home, bool share) {
      return new (home) LogBrancher(home,share,*this);
    }
    
    virtual bool status(const Space& home) const;
    
    virtual void print(const Space& home, const Choice& c, unsigned int a,
                       std::ostream& o) const;
    
  };

  GECODE_FLATZINC_EXPORT void branch(Home home, SymbolTable<SymbolEntry>& s, std::vector<int>& arrays, std::istream& log);

}}