#include "Server.h"
#include <cstddef>

Server *Server::_instance = nullptr;

Server *Server::getInstance() {
  if (!_instance)
    return new Server();

  return _instance;
}
