#ifndef CONNECTOR
#define CONNECTOR

#include "message.pb.hh"
#include "zmq.hpp"

namespace message {
  class Node;
}

namespace Profiling {

  class Node;

  enum NodeStatus {
    SOLVED = 0,
    FAILED = 1,
    BRANCH = 2,
    SKIPPED = 6,
    MERGING = 7
  };

  class Connector {

  private:

    const unsigned int port;
    unsigned int _thread_id;

    zmq::context_t context;
    zmq::socket_t socket;

    void sendOverSocket(const message::Node& msg);

  public:

    Connector(unsigned int port, unsigned int tid = 0);

    /// connect to a socket via port specified in the construction (6565 by default)
    void connect();

    // sends START_SENDING message to the Profiler with a model name
    void restart(const std::string& file_path = "", int restart_id = -1);

    void done();

    /// disconnect from a socket
    void disconnect();

    void sendNode(int sid,
                  int pid,
                  int alt,
                  int kids,
                  NodeStatus status,
                  const char* label,
                  unsigned int thread = -1,
                  int restart = -1,
                  float domain = -1,
                  const std::string& nogood = "",
                  const std::string& info = "");

    void sendNode(const Profiling::Node& node);

  };

  class Node {

  private:

    message::Node _node;

    const message::Node& get_node() const {
      return _node;
    }

  public:

    friend class Connector;

    Node(int sid, int pid, int alt, int kids, NodeStatus status);

    inline void set_label(const std::string& label) {
      _node.set_label(label);
    }

    inline void set_thread_id(unsigned int thread_id) {
      _node.set_thread_id(thread_id);
    }

  };

}

#endif