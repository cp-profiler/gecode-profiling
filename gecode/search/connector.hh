#ifndef CONNECTOR
#define CONNECTOR

#include <iostream>
#include <fstream>
#include <sstream>
#include <zmq.hpp>
#include <time.h>
#include <sys/time.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                ( std::ostringstream() << std::dec << x ) ).str()

enum MsgType {
      NODE_DATA = 1,
      DONE_SENDING = 2
};

struct Message {
  MsgType type;
  int sid;
  int parent;
  int alt;
  int kids;
  int status;
  char thread;


  void specifyNode(int _sid, int _parent, int _alt, int _kids, int _status, char _thread);
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

  void disconnectFromSocket();

  void sendNode(int sid, int parent, int alt, int kids, int status, int thread);

};

#endif