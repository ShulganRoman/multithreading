#include "TestDatabase.h"
#include "IRequest.h"
#include <regex>

TestDatabase::TestDatabase(boost::asio::io_context &io)
    : _strand(boost::asio::make_strand(io)) {}

void TestDatabase::execute(std::unique_ptr<IRequest> req) {
  boost::asio::post(_strand, [this, sql = req->getRequest()] {
    _history.push_back(sql);
    applySql(sql);
  });
}

const std::vector<std::string> &TestDatabase::history() const {
  return _history;
}

bool TestDatabase::userExists(size_t id) const { return _users.contains(id); }
bool TestDatabase::chatExists(size_t id) const { return _chats.contains(id); }

std::vector<std::string> TestDatabase::chatLog(size_t cid) const {
  auto it = _messages.find(cid);
  return it == _messages.end() ? std::vector<std::string>{} : it->second;
}

void TestDatabase::applySql(const std::string &s) {
  static std::regex insUser(
      R"(INSERT INTO users\s*\(id,\s*name\).*VALUES\s*\((\d+),\s*'([^']+)'\))",
      std::regex::icase);
  static std::regex delUser(R"(DELETE FROM users.*WHERE id\s*=\s*(\d+))",
                            std::regex::icase);
  static std::regex insChat(
      R"(INSERT INTO chats\s*\(id,\s*title\).*VALUES\s*\((\d+),\s*'([^']+)'\))",
      std::regex::icase);
  static std::regex insMsg(
      R"(INSERT INTO messages\s*\(chat_id,\s*user_id,\s*content\).*VALUES\s*\((\d+),\s*(\d+),\s*'([^']+)'\))",
      std::regex::icase);

  std::smatch m;
  if (std::regex_search(s, m, insUser))
    _users[std::stoull(m[1])] = m[2];
  else if (std::regex_search(s, m, delUser))
    _users.erase(std::stoull(m[1]));
  else if (std::regex_search(s, m, insChat))
    _chats[std::stoull(m[1])] = m[2];
  else if (std::regex_search(s, m, insMsg))
    _messages[std::stoull(m[1])].push_back(m[3]);
}

boost::asio::strand<boost::asio::io_context::executor_type>
TestDatabase::getStrand() {
  return _strand;
}
