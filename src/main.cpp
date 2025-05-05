#include "Server.h"
#include <boost/asio.hpp>

int main() {
  boost::asio::io_context io;

  try {
    auto server = Server::create(io,
                                 "dbname=messenger user=romanshulgan port=5432 "
                                 "password='[jxe,snmvjkjlsv' host=localhost",
                                 4444);
    std::cout << "Server started..." << std::endl;
    io.run();
  } catch (std::exception &e) {
    std::cerr << "Server exception: " << e.what() << std::endl;
  }
}
