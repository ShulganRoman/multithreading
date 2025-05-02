#include "Server.h"
#include <cstddef>
#include <string>

std::unique_ptr<Server> Server::create(boost::asio::io_context &io,
                                       const std::string &db_conn,
                                       uint16_t port) {
  return std::unique_ptr<Server>(new Server(io, db_conn, port));
}
