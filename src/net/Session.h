
#pragma once
#include <boost/asio.hpp>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
  using Handler =
      std::function<void(std::shared_ptr<Session>, const std::string &)>;

  Session(tcp::socket sock, Handler on_msg)
      : socket_(std::move(sock)), on_msg_(std::move(on_msg)) {}

  void start() { read(); }
  void send(std::string msg) {
    auto self = shared_from_this();
    boost::asio::post(socket_.get_executor(),
                      [self, msg = std::move(msg)]() mutable {
                        bool writing = !self->outbox_.empty();
                        self->outbox_.push_back(std::move(msg));
                        if (!writing)
                          self->do_write();
                      });
  }

  void setUsername(const std::string &name) { username_ = name; }
  const std::string &username() const { return username_; }

private:
  void do_write() {
    auto self = shared_from_this();
    boost::asio::async_write(socket_, boost::asio::buffer(outbox_.front()),
                             [self](boost::system::error_code ec, std::size_t) {
                               if (ec) {
                                 std::cerr << "write: " << ec.message() << '\n';
                                 return;
                               }
                               self->outbox_.pop_front();
                               if (!self->outbox_.empty())
                                 self->do_write();
                             });
  }

  void read() {
    auto self = shared_from_this();
    boost::asio::async_read_until(
        socket_, buf_, "\n", [self](boost::system::error_code ec, std::size_t) {
          if (ec) {
            std::cerr << "read: " << ec.message() << '\n';
            return;
          }
          std::istream is(&self->buf_);
          std::string line;
          std::getline(is, line);
          if (!line.empty() && line.back() == '\r')
            line.pop_back();
          self->on_msg_(self, line);
          self->read();
        });
  }

  tcp::socket socket_;
  boost::asio::streambuf buf_;
  std::deque<std::string> outbox_;
  std::string username_;
  Handler on_msg_;
};
