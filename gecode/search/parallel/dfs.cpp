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

#include <gecode/support.hh>

#ifdef GECODE_HAS_THREADS

#include <gecode/search/parallel/dfs.hh>

using cpprofiler::NodeStatus;

namespace Gecode { namespace Search { namespace Parallel {

  /*
   * Statistics
   */
  Statistics 
  DFS::statistics(void) const {
    Statistics s;
    for (unsigned int i=0; i<workers(); i++)
      s += worker(i)->statistics();
    return s;
  }


  /*
   * Engine: search control
   */
  void
  DFS::Worker::run(void) {
    Connector connector(_wid);

    pid = -1;
    int alt = -1;
    int kids = -1;

    connector.connect();
    std::cerr << "connected to socket! \n";
    
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
    // Peform initial delay, if not first worker
    if (this != engine().worker(0))
      Support::Thread::sleep(Config::initial_delay);
    // Okay, we are in business, start working
    while (true) {
      switch (engine().cmd()) {
      case C_WAIT:
        // Wait
        engine().wait();
        break;
      case C_TERMINATE:
        // Acknowledge termination request
        engine().ack_terminate();
        // Wait until termination can proceed
        engine().wait_terminate();
        // Terminate thread
        engine().terminated();
        return;
      case C_RESET:
        // Acknowledge reset request
        engine().ack_reset_start();
        // Wait until reset has been performed
        engine().wait_reset();
        // Acknowledge that reset cycle is over
        engine().ack_reset_stop();
        break;
      case C_WORK:
        // Perform exploration work
        {
          m.acquire();
          if (idle) {
            m.release();
            // Try to find new work
            // if (_wid != 0)
              // std::cerr << "stealing work, thread: " << _wid << std::endl;
            find();
            // if (_wid != 0)
              // std::cerr << "found work with parent: " << pid << " thread: " 
              //           << _wid << std::endl;

          } else if (cur != NULL) {
            start();
            if (stop(engine().opt())) {
              // Report stop
              m.release();
              engine().stop();
            } else {
              node++;
              std::ostringstream oss;

              if (path.entries() > 0) {
                Path::Edge& edge = path.top();
                pid = edge.pid();
                alt = std::min(edge.alt(), edge.choice()->alternatives() - 1);
                cur->print(*edge.choice(), alt, oss);
              }

              // sleep(1);

              switch (cur->status(*this)) {
              case SS_FAILED:
              {


                connector.createNode(
                    {static_cast<int32_t>(_nid), 0, static_cast<char>(wid())},
                    {static_cast<int32_t>(pid), 0, static_cast<char>(wid())}, alt, 0, cpprofiler::NodeStatus::FAILED)
                 .set_label(oss.str().c_str())
                 .send();

                fail++;
                delete cur;
                cur = NULL;
                path.next();
                m.release();
                break;
              }
              case SS_SOLVED:
                {

                  connector.createNode(
                      {static_cast<int32_t>(_nid), 0,static_cast<char>(wid())},
                      {static_cast<int32_t>(pid), 0, static_cast<char>(wid())}, alt, 0, cpprofiler::NodeStatus::SOLVED)
                   .set_label(oss.str().c_str())
                   .send();

                  // Deletes all pending branchers
                  (void) cur->choice();
                  Space* s = cur->clone(false);
                  delete cur;
                  cur = NULL;
                  path.next();
                  m.release();
                  engine().solution(s);
                }
                break;
              case SS_BRANCH:
                {
                  Space* c;
                  if ((d == 0) || (d >= engine().opt().c_d)) {
                    c = cur->clone();
                    d = 1;
                  } else {
                    c = NULL;
                    d++;
                  }
                  const Choice* ch = path.push(*this, _nid, cur,c);

                  kids = ch->alternatives();

                  connector.createNode(
                      {static_cast<int32_t>(_nid), 0, static_cast<char>(wid())},
                      {static_cast<int32_t>(pid), 0, static_cast<char>(wid())}, alt, kids, cpprofiler::NodeStatus::SOLVED)
                   .set_label(oss.str().c_str())
                   .send();


                  cur->commit(*ch,0);
                  m.release();
                }
                break;
              default:
                GECODE_NEVER;
              }

              _nid += engine().workers();
            }
          } else if (!path.empty()) {
            cur = path.recompute(d,engine().opt().a_d,*this);
            if (cur == NULL)
              path.next();
            m.release();
          } else {
            idle = true;
            path.ngdl(0);
            m.release();
            // Report that worker is idle
            engine().idle();
          }
        }
        break;
      default:
        GECODE_NEVER;
      }
    }
  }


  /*
   * Perform reset
   *
   */
  void
  DFS::reset(Space* s) {
    // Grab wait lock for reset
    m_wait_reset.acquire();
    // Release workers for reset
    release(C_RESET);
    // Wait for reset cycle started
    e_reset_ack_start.wait();
    // All workers are marked as busy again
    n_busy = workers();
    for (unsigned int i=1U; i<workers(); i++)
      worker(i)->reset(NULL,0);
    worker(0U)->reset(s,opt().nogoods_limit);
    // Block workers again to ensure invariant
    block();
    // Release reset lock
    m_wait_reset.release();
    // Wait for reset cycle stopped
    e_reset_ack_stop.wait();
  }



  /*
   * Create no-goods
   *
   */
  NoGoods&
  DFS::nogoods(void) {
    NoGoods* ng;
    // Grab wait lock for reset
    m_wait_reset.acquire();
    // Release workers for reset
    release(C_RESET);
    // Wait for reset cycle started
    e_reset_ack_start.wait();
    ng = &worker(0)->nogoods();
    // Block workers again to ensure invariant
    block();
    // Release reset lock
    m_wait_reset.release();
    // Wait for reset cycle stopped
    e_reset_ack_stop.wait();
    return *ng;
  }


  /*
   * Termination and deletion
   */
  DFS::~DFS(void) {
    Connector connector(opt().port);
    std::cerr << "sending done...";
    connector.connect();
    connector.done();
    connector.disconnect();

    terminate();
    heap.rfree(_worker);
  }

}}}

#endif

// STATISTICS: search-parallel
