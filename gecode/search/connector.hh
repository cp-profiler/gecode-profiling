#ifndef CONNECTOR
#define CONNECTOR

#include <iostream>
#include <iomanip>
#include <sstream>
#include <zmq.hpp>
#include <ctime>
#include <chrono>

using namespace std::chrono;

namespace message {
  class Node;
}

class Connector {

private:

  const unsigned int port;
  char _thread_id;
  
  zmq::context_t context;
  zmq::socket_t socket;

  system_clock::time_point begin_time;
  system_clock::time_point current_time;

  void sendOverSocket(message::Node &msg);

public:

  Connector(unsigned int port, char tid = 0);

  void connectToSocket();

  // sends START_SENDING message to Gist with model name
  void restartGist(int restart_id, const std::string& file_path);

  void disconnectFromSocket();
  void sendDoneSending();

  void sendNode(int sid, int pid, int alt, int kids, int status, const char* label, char thread, int restart = -1, float domain = -1);
  void sendNode(int sid, int pid, int alt, int kids, int status, char thread, int restart = -1, float domain = -1);

};

#endif