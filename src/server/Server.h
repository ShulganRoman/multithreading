#include "Database.h"
#include "Session.h"
#include <boost/asio.hpp>
#include <iostream>
#include <memory>

using namespace boost::asio::ip;

class Server {
public:
  static std::unique_ptr<Server> create(boost::asio::io_context &io,
                                        const std::string &db_conn,
                                        uint16_t port);

private:
  boost::asio::io_context &io_;
  tcp::acceptor acceptor_;
  Database database_;

  Server(boost::asio::io_context &io, const std::string &db_conn, uint16_t port)
      : io_(io), acceptor_(io_, tcp::endpoint(tcp::v4(), port)),
        database_(io_, db_conn) {
    do_accept();
  }

  void do_accept() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket sock) {
          if (!ec) {
            std::make_shared<Session>(std::move(sock))->start();
          } else {
            std::cerr << "Accept error: " << ec.message() << std::endl;
          }
          do_accept();
        });
  }
};
