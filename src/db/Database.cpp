#include "Database.h"
#include "IRequest.h"

#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <pqxx/pqxx>
#include <utility>

Database::Database(boost::asio::io_context &io, std::string connStr)
    : _io(io), _strand(boost::asio::make_strand(io)),
      _connStr(std::move(connStr)) {}

void Database::execute(std::unique_ptr<IRequest> request) {
  boost::asio::post(_strand,
                    [req = std::move(request), connStr = _connStr]() mutable {
                      try {
                        pqxx::connection conn{connStr};
                        pqxx::work tx{conn};
                        tx.exec(req->getRequest());
                        tx.commit();
                      } catch (const std::exception &ex) {
                        std::cerr << "[DB] " << ex.what() << '\n';
                      }
                    });
}

boost::asio::strand<boost::asio::io_context::executor_type>
Database::getStrand() {
  return _strand;
}
