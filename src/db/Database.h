#pragma once
#include "IDatabase.h"

#include <boost/asio.hpp>
#include <memory>
#include <string>

class Database final : public IDatabase {
public:
  Database(boost::asio::io_context &io, std::string connStr);

  void execute(std::unique_ptr<IRequest> request) override;
  boost::asio::strand<boost::asio::io_context::executor_type> getStrand();

private:
  boost::asio::io_context &_io;
  boost::asio::strand<decltype(_io.get_executor())> _strand;
  std::string _connStr;
};
