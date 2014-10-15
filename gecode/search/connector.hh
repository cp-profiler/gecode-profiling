#ifndef CONNECTOR
#define CONNECTOR

#include <iostream>
#include <sstream>
#include <zmq.hpp>
#include <time.h>
#include <sys/time.h>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                ( std::ostringstream() << std::dec << x ) ).str()

enum MsgType {
  NODE_DATA = 1,
  DONE_SENDING = 2,
  START_SENDING = 3
};

struct Message {
  static const int LABEL_SIZE = 16;

  MsgType type;
  int sid;
  int parent;
  int alt;
  int kids;
  int status;
  int restart_id;
  char thread;
  char label[16];


  Message(void);

  void specifyNode(int _sid, int _parent, int _alt, int _kids,
                   int _status, const char* label, char _thread);

  void specifyNode(int _sid, int _parent, int _alt, int _kids,
                   int _status, char _thread);

};

class Connector {

  // static Connector* inst;

  Message data;
  zmq::context_t* context;
  zmq::socket_t* socket;
  std::ofstream* ofs;

  char _thread_id;

  void sendOverSocket(Message &msg);


public:

  Connector(char tid);
  Connector();

  ~Connector();

  // static Connector& obj(void);

  void connectToSocket();

  void restartGist(int restart_id); // sends START_SENDING message to Gist

  void disconnectFromSocket();

  void sendNode(int sid, int parent, int alt, int kids, int status, const char* label, int thread, int restart = 0);
  
  void sendNode(int sid, int parent, int alt, int kids, int status, int thread, int restart = -1);

};

#endif