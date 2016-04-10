#ifndef TCP_CONNECTOR_H_
#define TCP_CONNECTOR_H_

#include <memory>

#include "common.h"
#include "tcp_stream.h"

namespace Tiny {
  typedef 
  class TCPConnector {
   public:
    shared_ptr<TCPStream> connect(const char *host_name, int port); 
  };
}

#endif
