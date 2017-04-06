/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 *  Main authors:
 *     Christian Schulte <schulte@gecode.org>
 *
 *  Copyright:
 *     Christian Schulte, 2009
 *
 *  Last modified:
 *     $Date$ by $Author$
 *     $Revision$
 *
 *  This file is part of Gecode, the generic constraint
 *  development environment:
 *     http://www.gecode.org
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __GECODE_SEARCH_SEQUENTIAL_DFS_HH__
#define __GECODE_SEARCH_SEQUENTIAL_DFS_HH__

#include <gecode/search.hh>
#include <gecode/search/support.hh>
#include <gecode/search/worker.hh>
#include <gecode/search/sequential/path.hh>

#include "submodules/cpp-integration/connector.hh"

namespace Gecode { namespace Search { namespace Sequential {


  /// Depth-first search engine implementation
  class DFS : public Worker {
  private:
    /// Search options
    Options opt;
    /// Current path ins search tree
    Path path;
    /// Current space being explored
    Space* cur;
    /// Distance until next clone
    unsigned int d;
    /// Socket handler
    Connector *connector;

    std::ostringstream oss;

  public:
    /// Initialize for space \a s with options \a o
    /// isRestarts = true if running -restart option
    DFS(Space* s, const Options& o, bool isRestarts = false);
    /// %Search for next solution
    Space* next(void);
    /// Return statistics
    Statistics statistics(void) const;
    /// Reset engine to restart at space \a s
    void reset(Space* s);
    /// Return no-goods
    NoGoods& nogoods(void);
    /// Destructor
    ~DFS(void);
  };

  forceinline 
  DFS::DFS(Space* s, const Options& o, bool isRestarts)
    : opt(o), path(opt.nogoods_limit), d(0) {
      // std::cout << "filename: " << o.problem_name << std::endl;

      if (opt.sendNodes) {
        connector = new Connector(opt.port == 0 ? 6565 : o.port);
        connector->connect();

        if (isRestarts)
          connector->restart(o.problem_name, 0, "", opt.execution_id);
        else
          connector->restart(o.problem_name, -1, "", opt.execution_id);
      }
      
    if ((s == NULL) || (s->status(*this) == SS_FAILED)) { 
      fail++;
      cur = NULL;
      if (!opt.clone)
        delete s;
    } else {
      cur = snapshot(s,opt);
    }
  }

  forceinline void
  DFS::reset(Space* s) {
    restart++;
    delete cur;
    path.reset();
    d = 0;
    if ((s == NULL) || (s->status(*this) == SS_FAILED)) {
      delete s;
      cur = NULL;
    } else {
      cur = s;
    }
    Worker::reset();
  }

  forceinline NoGoods&
  DFS::nogoods(void) {
    return path;
  }

  forceinline Space*
  DFS::next(void) {
    int pid = -1;
    int alt = -1;
    int kids = -1;
    
    /*
     * The engine maintains the following invariant:
     *  - If the current space (cur) is not NULL, the path always points
     *    to exactly that space.
     *  - If the current space (cur) is NULL, the path always points
     *    to the next space (if there is any).
     *
     * This invariant is needed so that no-goods can be extracted properly
     * when the engine is stopped or has found a solution.
     *
     */
    start();
    while (true) {
      if (stop(opt))
        return NULL;
      while (cur == NULL) {
        if (path.empty())
          return NULL;
        cur = path.recompute(d,opt.a_d,*this);
        if (cur != NULL)
          break;
        path.next();
      }
      node++;
      if (opt.sendNodes) {
        oss.str("");
        oss.clear();
        if (node == 1) {
          pid = -1;
          alt = -1;
        } else {
          Path::Edge& edge = path.top();
          pid = edge.pid();
          alt = std::min(edge.alt(), edge.choice()->alternatives() - 1);
          cur->print(*edge.choice(), alt, oss);
        }
      }


      switch (cur->status(*this)) {
      case SS_FAILED:
        if (opt.sendNodes) {

          std::string info;
          if (opt.sendDomains) { info += cur->getDomains(); }

          /// **** JUST FOR DEBUGGING ****
            // info += "domain stack size: " + std::to_string(path.domainStack().size()) + "\n";

            float domain_diff = cur->calcDomainSizeRed(nullptr, path.topDomainInfo());

            // assert(domain_diff < 1.1);
            if (domain_diff > 1.1) {
              std::cerr << "(!) domain_diff: " << domain_diff << '\n';
            }

            info += std::string("full domain size: ")
                    + std::to_string(cur->getDomainSize()) + "\n";

            info += std::string("domain reduction: ")
                    + std::to_string(::exp(domain_diff)) + "\n";
          /// ****************************

          connector->createNode(node, pid, alt, 0, NodeStatus::FAILED)
           .set_label(oss.str().c_str())
           .set_thread_id(0)
           .set_restart_id(restart)
           // NOTE(maxim): changed to domain reduction for now
           .set_domain_size(std::exp(domain_diff))
           // .set_domain_size(cur->getDomainSize())
           .set_info(info)
           .send();
        }
        fail++;
        delete cur;
        cur = NULL;
        path.next();
        break;
      case SS_SOLVED:
        {
          if (opt.sendNodes) {

            std::string info;
            if (opt.sendDomains) { info += cur->getDomains(); }
            /// **** JUST FOR DEBUGGING ****
            // info += "domain stack size: " + std::to_string(path.domainStack().size()) + "\n";

            float domain_diff = cur->calcDomainSizeRed(nullptr, path.topDomainInfo());

            // assert(domain_diff < 1.1);
            if (domain_diff > 1.1) {
              std::cerr << "(!) domain_diff: " << domain_diff << '\n';
            }

            info += std::string("domain reduction: ")
                    + std::to_string(::exp(domain_diff)) + "\n";
            /// ****************************
            connector->createNode(node, pid, alt, 0, NodeStatus::SOLVED)
             .set_label(oss.str().c_str())
             .set_thread_id(0)
             .set_restart_id(restart)
             // NOTE(maxim): changed to domain reduction for now
             .set_domain_size(std::exp(domain_diff))
             // .set_domain_size(cur->getDomainSize())
             .set_info(info)
             .send();
          }
          // Deletes all pending branchers
          (void) cur->choice();
          Space* s = cur;
          cur = NULL;
          path.next();
          return s;
        }
      case SS_BRANCH:
        {
          Space* c;
          if ((d == 0) || (d >= opt.c_d)) {
            c = cur->clone();
            d = 1;
          } else {
            c = NULL;
            d++;
          }
          const Choice* ch = path.push(*this,node,cur,c);
          if (opt.sendNodes) {
            kids = ch->alternatives();

            std::string info;
            if (opt.sendDomains) { info += cur->getDomains(); }

            if (path.domainStack().size() == 0) {
              path.domainStack().push(LastDomainInfo{-1, -1, -1});
            } else {
              /// copy over last item, will be overridden
              path.domainStack().push(path.topDomainInfo());
            }

            /// **** JUST FOR DEBUGGING ****
            info += std::string("full domain size: ")
                    + std::to_string(cur->getDomainSize()) + "\n";

            float domain_diff = cur->calcDomainSizeRed(ch, path.topDomainInfo());

            // assert(domain_diff < 1.1);
            if (domain_diff > 1.1) {
              std::cerr << "(!) domain_diff: " << domain_diff << '\n';
            }

            info += std::string("domain reduction: ")
                    + std::to_string(std::exp(domain_diff)) + "\n";
            info += "domain stack size: " + std::to_string(path.domainStack().size()) + "\n";
            info += "edge stack size: " + std::to_string(path.entries()) + "\n";
            /// ****************************

            connector->createNode(node, pid, alt, kids, NodeStatus::BRANCH)
             .set_label(oss.str().c_str())
             .set_thread_id(0)
             .set_restart_id(restart)
             // NOTE(maxim): changed to domain reduction for now
             .set_domain_size(std::exp(domain_diff))
             // .set_domain_size(cur->getDomainSize())
             .set_info(info)
             .send();

          }
          cur->commit(*ch,0);
          break;
        }
      default:
        GECODE_NEVER;
      }
    }
    GECODE_NEVER;
    return NULL;
  }

  forceinline Statistics
  DFS::statistics(void) const {
    return *this;
  }

  forceinline 
  DFS::~DFS(void) {
    delete cur;
    if (opt.sendNodes) {
      connector->done();
      connector->disconnect();
      delete connector;
    }
    path.reset();
  }

}}}

#endif

// STATISTICS: search-sequential
