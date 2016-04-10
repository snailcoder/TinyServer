#include <arpa/inet.h>

#include "tcp_stream.h"

namespace Tiny {
  TCPStream::TCPStream(int sd, const sockaddr_in &addr) : sock_fd_(sd){
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(addr.sin_addr), ip, INET_ADDRSTRLEN);
    peer_ip_ = ip;
    peer_port_ = ntohs(addr.sin_port);
  }

  TCPStream::~TCPStream() {
    close(sock_fd_);
  }

  string TCPStream::peer_ip() const {
    return peer_ip_;
  }

  int TCPStream::peer_port() const {
    return peer_port_;
  }
}
