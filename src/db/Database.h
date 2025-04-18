#include "requests/IRequest.h"
#include <memory>
#include <pqxx/pqxx>
#include <string>

using namespace pqxx;
using namespace std;

class Database {
public:
  explicit Database(std::string cxStr)
      : _cxStr(std::move(cxStr)), // ① сохраняем **копию** в член‑данном
        _cx{pqxx::zview(_cxStr)}, // ② инициализируем connection ЕЁ данными
        _tx{std::make_unique<pqxx::work>(_cx)} {}

  // правило пяти: запрещаем копирование, разрешаем перемещение
  Database(const Database &) = delete;
  Database &operator=(const Database &) = delete;
  Database(Database &&) = default;
  Database &operator=(Database &&) = default;

  void clearQuery() { _query.clear(); }
  void commit() { _tx->commit(); }
  void abort() {
    _tx.reset();

    {
      pqxx::work tx{_cx};
      tx.exec(IRequest::restartId());
      tx.commit();
    }

    _tx = std::make_unique<pqxx::work>(_cx);
    _query.clear();
  }

  void push_request(std::unique_ptr<IRequest> req) {
    _query.push_back(std::move(req));
  }
  void execQuery() {
    for (auto &r : _query)
      _tx->exec(r->buildRequest());
  }
  void execAndClear() {
    execQuery();
    clearQuery();
  }

  pqxx::work &tx() { return *_tx; } // удобный alias
  const std::string &connStr() const { return _cxStr; }

private:
  std::string _cxStr;   // строка живёт столько же, сколько Database
  pqxx::connection _cx; // держит zview на _cxStr
  std::unique_ptr<pqxx::work> _tx;
  std::vector<std::unique_ptr<IRequest>> _query;
};
// TODO: Перенести все в Database.cpp
// сообщение в базу данных и из нее
