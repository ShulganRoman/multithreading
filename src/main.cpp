#include "Server.h"
#include <boost/asio.hpp>

int main() {
  boost::asio::io_context io;

  try {
    auto server = Server::create(io,
                                 "dbname=messenger user=romansulgan port=5432 "
                                 "password='[jxe,snmvjkjlsv' host=localhost",
                                 4444);

    io.run();
  } catch (std::exception &e) {
    std::cerr << "Server exception: " << e.what() << std::endl;
  }
}
