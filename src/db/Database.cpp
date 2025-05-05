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

using DbHandler = std::function<void(pqxx::result)>;

void Database::execute(std::unique_ptr<IRequest> request, DbHandler handler) {
  boost::asio::post(_strand,
                    [req = std::move(request), handler = std::move(handler),
                     connStr = _connStr]() mutable {
                      try {
                        pqxx::connection conn{connStr};
                        pqxx::nontransaction tx{conn};
                        pqxx::result res = tx.exec(req->getRequest());

                        if (handler)
                          handler(std::move(res));
                      } catch (const std::exception &ex) {
                        std::cerr << "[DB] " << ex.what() << '\n';
                        if (handler)
                          handler({});
                      }
                    });
}

boost::asio::strand<boost::asio::io_context::executor_type>
Database::getStrand() {
  return _strand;
}
