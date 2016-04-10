#ifndef TCP_STREAM_H_
#define TCP_STREAM_H_

#include <sys/socket.h>
#include <unistd.h>

#include "common.h"

namespace Tiny {
  class TCPStream {
   public:
    ~TCPStream()

    string peer_ip() const;
    int peer_port() const;

   private:
    TCPStream(int sd, sockaddr_in *addr);
    TCPStream();
    TCPStream(const TCPStream &stream);

    int sock_fd_;
    string peer_ip_;
    int peer_port_;
  };
}

#endif
