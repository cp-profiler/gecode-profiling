#include <gecode/search/connector.hh>
#include <cstring>
#include <unistd.h>

Message::Message(void) {
  strcpy(label, "undefined");
}

void Message::specifyNode(int _sid, int _parent, int _alt, int _kids,
                          int _status, const char* _label, char _thread) {
  std::memcpy(label, _label, 16);
  type = NODE_DATA;
  sid = _sid;
  parent = _parent;
  alt = _alt;
  kids = _kids;
  status = _status;
  thread = _thread;
}

void Message::specifyNode(int _sid, int _parent, int _alt, int _kids,
                          int _status, char _thread) {
  std::memcpy(label, "undefined", Message::LABEL_SIZE);
  type = NODE_DATA;
  sid = _sid;
  parent = _parent;
  alt = _alt;
  kids = _kids;
  status = _status;
  thread = _thread;
}

Connector::Connector(char tid) : _thread_id(tid) {
  context = new zmq::context_t(1);
  socket = new zmq::socket_t(*context, ZMQ_PUSH);
}

Connector::Connector() {
  context = new zmq::context_t(1);
  socket = new zmq::socket_t(*context, ZMQ_PUSH);
}

Connector::~Connector() {
  delete context;
  delete socket;
}

// Connector& Connector::obj(void) {
//   if (!inst)
//     inst = new Connector();
//   return *inst;
// }

void Connector::sendOverSocket(Message &msg) {
  zmq::message_t request(sizeof(msg));
  memcpy(request.data(), &data, sizeof(msg));
  int ne = socket->send(request);
    
  if (ne == -1) 
    std::cerr << "error while sending over socket\n";
}

void Connector::sendNode(int sid, int parent, int alt, int kids,
                         int status, const char* label, int thread, int restart) {

  data.restart_id = restart;

  data.specifyNode(sid, parent, alt, kids, status, label, thread);
  // std::cerr << "Received node: \t" << sid << " " << parent << " "
  //                   << alt << " " << kids << " " << status << " wid: "
  //                   << (int)thread << " restart: " << restart << std::endl;

  sendOverSocket(data);
}

void Connector::sendNode(int sid, int parent, int alt, int kids,
                         int status, int thread, int restart) {

  // usleep(1000);
  data.restart_id = restart;

  data.specifyNode(sid, parent, alt, kids, status, thread);
  sendOverSocket(data);
}

void Connector::restartGist(int restart_id) {
  std::cerr << "restarting gist, restart_id: " << restart_id << "\n";
  data.type = START_SENDING;
  data.restart_id = restart_id;
  sendOverSocket(data);
}

void Connector::connectToSocket() {
  socket->connect("tcp://localhost:5555");
}

void Connector::disconnectFromSocket() {
  data.type = DONE_SENDING;
  sendOverSocket(data);
  socket->close();
  sleep(1);
  
}

// Connector* Connector::inst = NULL;