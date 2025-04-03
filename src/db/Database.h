#include "requests/Request.h"
#include <functional>
#include <pqxx/pqxx>
#include <string>
#include <vector>

class Database { // TODO: Доделать автоматизацию типов (id, name)
public:
  Database(std::string connectionString) // TODO: implement try catch
      : _connectionString(connectionString) {}

  ~Database() = default;

  void setRequest(Request &request) { _query.push_back(request); }

  void startQuery() {
    for (auto i : _query)
      i.get().exec(pqxx::work(_connection));
  }

  void clearQuery() { _query.clear(); }

private:
  pqxx::connection _connection;
  std::vector<std::reference_wrapper<Request>> _query;

  std::string _connectionString;
}; // TODO: Перенести все в Database.cpp
