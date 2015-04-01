#include <gecode/search/connector.hh>
#include <cstring>
#include <string>
#include <unistd.h>

Message::Message(void) {
  strcpy(label, "");
}

void Message::specifyNode(int _sid, int _parent, int _alt, int _kids,
                          int _status, const char* _label, char _thread,
                          unsigned long long _time, float _domain) {
  std::memcpy(label, _label, Message::LABEL_SIZE - 1);
  type = NODE_DATA;
  sid = _sid;
  parent = _parent;
  alt = _alt;
  kids = _kids;
  status = _status;
  time = _time;
  thread = _thread;
  domain = _domain;
}

void Message::specifyNode(int _sid, int _parent, int _alt, int _kids,
                          int _status, char _thread, unsigned long long _time,
                          float _domain) {
  std::memcpy(label, "", Message::LABEL_SIZE - 1);
  type = NODE_DATA;
  sid = _sid;
  parent = _parent;
  alt = _alt;
  kids = _kids;
  status = _status;
  time = _time;
  thread = _thread;
  domain = _domain;
}

Connector::Connector(char tid) : _thread_id(tid) {
  begin_time = system_clock::now();
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

void Connector::sendNode(int sid,
                         int parent,
                         int alt,
                         int kids,
                         int status,
                         const char* label,
                         char thread,
                         int restart,
                         float domain
) {

  current_time = system_clock::now();

  unsigned long long timestamp = static_cast<long long>(duration_cast<microseconds>(current_time - begin_time).count());

  data.restart_id = restart;

  // std::cout << domain << std::endl;

  data.specifyNode(sid, parent, alt, kids, status, label, thread, timestamp, domain);
  // std::cerr << "Received node: \t" << sid << " " << parent << " "
  //                   << alt << " " << kids << " " << status << " wid: "
  //                   << (int)thread << " restart: " << restart << std::endl;
  sendOverSocket(data);
}

void Connector::sendNode(int sid,
                         int parent,
                         int alt,
                         int kids,
                         int status,
                         char thread,
                         int restart,
                         float domain
) {

  current_time = system_clock::now();

  unsigned long long timestamp = static_cast<long long>(duration_cast<microseconds>(current_time - begin_time).count());

  // usleep(1000);
  data.restart_id = restart;
  data.specifyNode(sid, parent, alt, kids, status, thread, timestamp, domain);

  // std::cout << domain << std::endl;
  sendOverSocket(data);
}

void Connector::restartGist(int restart_id, const std::string& file_path) {
  std::cerr << "restarting gist, restart_id: " << restart_id << "\n";
  data.type = START_SENDING;
  data.restart_id = restart_id;

  /// extract fzn file name
  std::string name(file_path);
  int pos = name.find_last_of('/');
  if (pos > 0) {
    name = name.substr(pos + 1, name.length() - pos - 1);
  }

  std::memcpy(data.label, name.c_str(), Message::LABEL_SIZE - 1);

  data.label[Message::LABEL_SIZE - 1] = '\0';
  sendOverSocket(data);
}

void Connector::connectToSocket() {
  socket->connect("tcp://localhost:6565");
  begin_time = system_clock::now();
  std::cout << "sending over port: 6565\n";
}

void Connector::disconnectFromSocket() {
  data.type = DONE_SENDING;
  sendOverSocket(data);
  socket->close();
  std::cout << "sending DONE_SENDING\n";
  sleep(1);
  
}

// Connector* Connector::inst = NULL;