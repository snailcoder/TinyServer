#include <cstring>

#include "tcp_connector.h"

shared_ptr<TCPStream> TCPConnector::connect(const char *host_name,
                                            int port) {
  sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));

  int sd = socket(AF_INET, SOCK_STREAM, 0);
  if (sd < 0) {
    return shared_ptr<TCPStream>();
  }

  addrinfo *res;
  int result = getaddrinfo(host_name, NULL, NULL, &res);
  if (result != 0) {
    return shared_ptr<TCPStream>();
  }
  memcpy(&(addr.sin_addr), 
         &(static_cast<sockaddr_in*>(res->ai_addr)->sin_addr), 
         sizeof(in_addr));
  freeaddrinfo(res);

  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  if (::connect(sd, static_cast<sockaddr*>(&addr), sizeof(addr)) < 0) {
    return shared_ptr<TCPStream>();
  }
  return shared_ptr<TCPStream>(new TCPStream(sd, &addr));
}
