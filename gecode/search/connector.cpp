#include <gecode/search/connector.hh>
#include <gecode/search/message.pb.hh>
#include <cstring>
#include <string>
#include <unistd.h>


Connector::Connector(unsigned int _port, char tid)
  : port(_port), context(1), socket(context, ZMQ_PUSH) {
  begin_time = system_clock::now(); /// TODO: should be removed?
}


inline void Connector::sendOverSocket(message::Node &msg) {
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

void Connector::sendNode(int sid,
                         int pid,
                         int alt,
                         int kids,
                         int status,
                         const char* label,
                         char thread,
                         int restart,
                         float domain)
{
  current_time = system_clock::now();

  unsigned long long timestamp = static_cast<long long>(duration_cast<microseconds>(current_time - begin_time).count());

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

  sendOverSocket(node);
}

void Connector::sendNode(int sid, int pid, int alt, int kids, int status, char thread, int restart, float domain) {
  sendNode(sid, pid, alt, kids, status, "", thread, restart, domain);
}


void Connector::restartGist(int restart_id, const std::string& file_path) {
  // std::cerr << "restarting gist, restart_id: " << restart_id << "\n";

  message::Node dummy_node;
  dummy_node.set_type(message::Node::START);

  /// new: is this really required? old: this needs to be changed to 0 if restarts
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
  std::string address = "tcp://localhost:" + std::to_string(port);
  socket.connect(address.c_str());
  begin_time = system_clock::now();
  // std::cout << "sending over port: " << port << "\n";
}

void Connector::disconnectFromSocket() {
  message::Node dummy_node;
  dummy_node.set_type(message::Node::DONE);

  sendOverSocket(dummy_node);

  socket.close();
  sleep(1); /// is that really necessary?

}

void Connector::sendDoneSending() {
  message::Node dummy_node;
  dummy_node.set_type(message::Node::DONE);
  sendOverSocket(dummy_node);

  // std::cout << "sending DONE_SENDING\n";
}