#include "Creatable.h"
#include "Request.h"
#include <pqxx/pqxx>

class Create : public Request {
  Create(Creatable *obj) : _obj(obj) {}

  pqxx::result exec(pqxx::work work) override {
    return work.exec(_obj->getString());
  }

private:
  Creatable *_obj;
};
