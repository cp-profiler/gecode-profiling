#include <gecode/search/connector.hh>
#include <string>

void Message::specifyNode(int _sid, int _parent, int _alt, int _kids, int _status, char _thread) {
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

void Connector::sendNode(int sid, int parent, int alt, int kids, int status, int thread) {
  // std::string filename = std::string("stream") + SSTR(thread) + std::string(".txt");
  // FILE *f = fopen(filename.c_str(), "a");

  timespec ts;

  #ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
  clock_serv_t cclock;
  mach_timespec_t mts;
  host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
  clock_get_time(cclock, &mts);
  mach_port_deallocate(mach_task_self(), cclock);
  ts.tv_sec = mts.tv_sec;
  ts.tv_nsec = mts.tv_nsec;

  #else
  clock_gettime(CLOCK_REALTIME, &ts);
  #endif

  std::string text = SSTR((long long)ts.tv_sec) + "." + SSTR(ts.tv_nsec) + 
                     "\tsid: " + SSTR(sid) + "\tpid: " + SSTR(parent) +
                     "\talt: " + SSTR(alt) + "\tkids: " + SSTR(kids) +
                     "\tstatus: " + SSTR(status) + "\tthread: " + SSTR(thread) + "\n";
  // std::cerr << sid << std::endl;
  // *ofs << text;

  // fwrite (text.c_str(), sizeof(char), strlen(text.c_str()), f);
  // fclose (f);

  data.specifyNode(sid, parent, alt, kids, status, thread);
  sendOverSocket(data);
}

// void Connector::sendNode(int sid, int parent, int alt, int kids, int status) {
//   std::cout << "sid: " << sid << " parent: " << parent << " alt: " << alt
//             << " kids: " << kids << " status: " << status << std::endl;
// }


void Connector::connectToSocket() {
  socket->connect("tcp://localhost:5555");

  // clear the file
  std::string filename = std::string("stream") + SSTR((int)_thread_id) + std::string(".txt");
  // ofs.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
  ofs = new std::ofstream(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
  
}

void Connector::disconnectFromSocket() {
  data.type = DONE_SENDING;
  sendOverSocket(data);
  ofs->close();
  sleep(1);
  
}

// Connector* Connector::inst = NULL;