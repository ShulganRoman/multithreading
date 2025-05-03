#pragma once

#include "MessageBuffer.h"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <iostream>
#include <memory>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
  Session(tcp::socket socket) : socket_(std::move(socket)) {}

  void start() {
    auto self = shared_from_this();
    boost::thread([self]() {
      try {
        self->do_communicate();
      } catch (std::exception &e) {
        std::cerr << "Session error: " << e.what() << std::endl;
      }
    }).detach();
  }

private:
  void do_communicate() {
    boost::asio::streambuf buf;

    while (true) {
      boost::system::error_code ec;
      std::size_t n = boost::asio::read_until(socket_, buf, "\n", ec);
      if (ec) {
        if (ec != boost::asio::error::eof)
          std::cerr << "Read error: " << ec.message() << std::endl;
        break;
      }

      std::istream is(&buf);
      std::string line;
      std::getline(is, line);

      MessageBuffer messageBuffer(line);

      std::cout << "Received: " << std::endl;
      std::cout << "  Username: " << messageBuffer.getUsername() << std::endl;
      std::cout << "  Id: " << messageBuffer.getId() << std::endl;
      std::cout << "  Datetime: " << messageBuffer.getDatetime() << std::endl;

      std::string response = messageBuffer.getMessage();
      boost::asio::write(socket_, boost::asio::buffer(response), ec);
      if (ec) {
        std::cerr << "Write error: " << ec.message() << std::endl;
        break;
      }
    }
  }

  tcp::socket socket_;
};
