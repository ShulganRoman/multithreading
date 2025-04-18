#include <boost/asio.hpp>
#include <iostream>

int main() {
  std::cout << "hello, world!" << std::endl;
  boost::asio::thread_pool();
}
