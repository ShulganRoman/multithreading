#pragma once

#include <boost/asio.hpp>
#include <memory>

class IRequest;

class IDatabase {
public:
  virtual ~IDatabase() = default;

  virtual void execute(std::unique_ptr<IRequest> request) = 0;
};
