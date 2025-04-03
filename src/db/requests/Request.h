#include <pqxx/pqxx>

class Request {
public:
  Request() = default;
  virtual pqxx::result exec(pqxx::transaction<> work) = 0;
  ~Request() = default;
};
