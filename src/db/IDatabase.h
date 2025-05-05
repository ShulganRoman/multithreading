#pragma once

#include <boost/asio.hpp>
#include <memory>
#include <pqxx/pqxx>

class IRequest;

using DbHandler = std::function<void(pqxx::result)>;

class IDatabase {
public:
  virtual ~IDatabase() = default;

  virtual void execute(std::unique_ptr<IRequest> request,
                       DbHandler handler = {}) = 0;
};
