#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <chrono>
#include <gtest/gtest.h>
#include <thread>

#include "Session.h"

using boost::asio::ip::tcp;

class SessionTest : public ::testing::Test {
protected:
  boost::asio::io_context io;
  tcp::acceptor acceptor{io, tcp::endpoint(tcp::v4(), 0)};

  unsigned short port() const { return acceptor.local_endpoint().port(); }
};

TEST_F(SessionTest, EchoSingleMessage) {

  tcp::socket client(io);
  client.connect({tcp::v4(), port()});
  tcp::socket server_socket(io);
  acceptor.accept(server_socket);

  auto session = std::make_shared<Session>(std::move(server_socket));
  session->start();

  const std::string request = "Hello GoogleTest\n";
  boost::asio::write(client, boost::asio::buffer(request));

  boost::asio::streambuf resp;
  boost::asio::read_until(client, resp, "\n");
  std::istream is(&resp);
  std::string line;
  std::getline(is, line);

  EXPECT_EQ(line, "Echo: Hello GoogleTest");
}

TEST_F(SessionTest, EchoMultipleMessages) {
  tcp::socket client(io);
  client.connect({tcp::v4(), port()});
  tcp::socket server_socket(io);
  acceptor.accept(server_socket);

  auto session = std::make_shared<Session>(std::move(server_socket));
  session->start();

  for (int i = 0; i < 5; ++i) {
    std::string msg = "msg" + std::to_string(i) + "\n";
    boost::asio::write(client, boost::asio::buffer(msg));

    boost::asio::streambuf resp;
    boost::asio::read_until(client, resp, "\n");
    std::istream is(&resp);
    std::string line;
    std::getline(is, line);

    EXPECT_EQ(line, "Echo: msg" + std::to_string(i));
  }
}

TEST_F(SessionTest, ClientCloseEndsSession) {
  tcp::socket client(io);
  client.connect({tcp::v4(), port()});
  tcp::socket server_socket(io);
  acceptor.accept(server_socket);

  auto session = std::make_shared<Session>(std::move(server_socket));
  session->start();

  client.close();

  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  SUCCEED();
}
