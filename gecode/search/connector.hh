#ifndef CONNECTOR
#define CONNECTOR

#include <zmq.hpp>

namespace message {
  class Node;
}

class Connector {

private:

  const unsigned int port;
  unsigned int _thread_id;

  zmq::context_t context;
  zmq::socket_t socket;

  void sendOverSocket(message::Node& msg);


public:

  Connector(unsigned int port, unsigned int tid = 0);

  void connectToSocket();

  // sends START_SENDING message to Gist with model name
  void restartGist(int restart_id, const std::string& file_path);

  void sendDoneSending();

  void disconnectFromSocket();

  void sendNode(int sid,
                int pid,
                int alt,
                int kids,
                int status,
                const char* label,
                unsigned int thread,
                int restart = -1,
                float domain = -1,
                const std::string& nogood = "",
                const std::string& info = "");

  void sendNode(int sid,
                int pid,
                int alt,
                int kids,
                int status,
                unsigned int thread,
                int restart = -1,
                float domain = -1,
                const std::string& nogood = "",
                const std::string& info = "");

};

#endif