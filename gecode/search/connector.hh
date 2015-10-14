#ifndef CONNECTOR
#define CONNECTOR

#include <gecode/search/message.pb.hh>
#include <gecode/search/zmq.hpp>

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

    Node createNode(int sid, int pid, int alt, int kids, NodeStatus status);

  };

  class Node {

  private:

    message::Node _node;
    Connector& _c;

    const message::Node& get_node() const {
      return _node;
    }

  public:

    friend class Connector;

    Node(int sid, int pid, int alt, int kids, NodeStatus status, Connector& c);

    Node(const Node& node);

    ~Node();

    void send();

    inline Node& set_label(const std::string& label) {
      _node.set_label(label);
      return *this;
    }

    inline Node& set_thread_id(unsigned int thread_id) {
      _node.set_thread_id(thread_id);
      return *this;
    }

    inline Node& set_restart_id(int restart_id) {
      _node.set_thread_id(restart_id);
      return *this;
    }

    inline Node& set_domain_size(float domain_size) {
      _node.set_domain_size(domain_size);
      return *this;
    }

    inline Node& set_nogood(const std::string& nogood) {
      _node.set_nogood(nogood);
      return *this;
    }

    inline Node& set_info(const std::string& nogood) {
      _node.set_nogood(nogood);
      return *this;
    }

  };

}

#endif
