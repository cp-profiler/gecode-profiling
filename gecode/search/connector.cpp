#include <gecode/search/connector.hh>

void Message::specifyNode(int _sid, int _parent, int _alt, int _kids, int _status, char _thread) {
  type = NODE_DATA;
  sid = _sid;
  parent = _parent;
  alt = _alt;
  kids = _kids;
  status = _status;
  thread = _thread;
}

Connector::Connector() {
  context = new zmq::context_t(1);
  socket = new zmq::socket_t(*context, ZMQ_PUSH);
}

Connector::~Connector() {
  delete context;
  delete socket;
  // delete inst;
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

void Connector::sendNode(int sid, int parent, int alt, int kids, int status, int thread) {
  data.specifyNode(sid, parent, alt, kids, status, thread);
  sendOverSocket(data);
}

// void Connector::sendNode(int sid, int parent, int alt, int kids, int status) {
//   std::cout << "sid: " << sid << " parent: " << parent << " alt: " << alt
//             << " kids: " << kids << " status: " << status << std::endl;
// }

void Connector::connectToSocket() {
  socket->connect("tcp://localhost:5555");
}

void Connector::disconnectFromSocket() {
  data.type = DONE_SENDING;
  sendOverSocket(data);
  sleep(1);
  
}

// Connector* Connector::inst = NULL;