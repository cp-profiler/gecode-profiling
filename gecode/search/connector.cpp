#include "gecode/search/connector.hh"
#include "gecode/search/message.pb.hh"
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()



Connector::Connector(unsigned int port, unsigned int tid)
: port(port), _thread_id(tid), context(1), socket(context, ZMQ_PUSH) {
  // begin_time = system_clock::now();
}

void Connector::sendOverSocket(message::Node &msg) {
  std::string msg_str;
  msg.SerializeToString(&msg_str);

  zmq::message_t request(msg_str.size());
  memcpy((void*)request.data(), msg_str.c_str(), msg_str.size());

  // Sometimes sending will fail with EINTR.  In this case, we try to
  // send the message again.
  while (true) {
    int failed_attempts = 0;
    try {
      bool sentOK = socket.send(request);
      // If sentOK is false, there was an EAGAIN.  We handle this the
      // same as EINTR.
      if (!sentOK) {
        failed_attempts++;
        if (failed_attempts > 10) abort();
        continue;
      }
      // Success: stop the loop.
      break;
    } catch (zmq::error_t &e) {
      failed_attempts++;
      if (failed_attempts > 10) abort();
      if (e.num() == EINTR) {
        continue;
      }
      // If it was something other than EINTR, rethrow the exception.
      throw e;
    }
  }
}

void Connector::sendNode(int sid, int pid, int alt, int kids,
                         int status, const char* label, unsigned int thread, int restart,
                         float domain, const std::string& nogood, const std::string& info) {

  // current_time = system_clock::now();
  // unsigned long long timestamp = static_cast<long long>(duration_cast<microseconds>(current_time - begin_time).count());

  message::Node node;

  node.set_type(message::Node::NODE);

  node.set_sid(sid);
  node.set_pid(pid);
  node.set_alt(alt);
  node.set_kids(kids);

  node.set_status(static_cast<message::Node::NodeStatus>(status));
  node.set_label(label);
  node.set_thread_id(thread);
  node.set_restart_id(restart);
  node.set_domain_size(domain);
  // node.set_solution(solution);
  node.set_nogood(nogood);
  node.set_info(info);

  sendOverSocket(node);
}

void Connector::sendNode(int sid, int pid, int alt, int kids,
                         int status, unsigned int thread, int restart, float domain,
                         const std::string& nogood, const std::string& info) {

  sendNode(sid, pid, alt, kids, status, "n/a", thread, restart, domain, nogood, info);
}

void Connector::restartGist(int restart_id, const std::string& file_path) {
  // std::cerr << "restarting gist, restart_id: " << restart_id << "\n";

  message::Node dummy_node;
  dummy_node.set_type(message::Node::START);

  /// should it be restart_id instead?
  dummy_node.set_restart_id(-1);

  /// extract fzn file name
  std::string name(file_path);
  int pos = name.find_last_of('/');
  if (pos > 0) {
    name = name.substr(pos + 1, name.length() - pos - 1);
  }

  dummy_node.set_label(name);

  sendOverSocket(dummy_node);
}

void Connector::connectToSocket() {
  std::string address = "tcp://localhost:" + SSTR(port);
  socket.connect(address.c_str());
  std::cout << "sending over port: " << port << "\n";
}

void Connector::sendDoneSending() {
  message::Node dummy_node;
  dummy_node.set_type(message::Node::DONE);
  sendOverSocket(dummy_node);
}

void Connector::disconnectFromSocket() {

  message::Node dummy_node;
  dummy_node.set_type(message::Node::DONE);
  sendOverSocket(dummy_node);
  // socket.close();
  // sleep(1);
}

