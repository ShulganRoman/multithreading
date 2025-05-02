#pragma once
#include "IDatabase.h"
#include <boost/asio.hpp>
#include <boost/asio/strand.hpp>
#include <string>
#include <unordered_map>
#include <vector>

class TestDatabase final : public IDatabase {
public:
  explicit TestDatabase(boost::asio::io_context &io);

  void execute(std::unique_ptr<IRequest> request) override;

  bool userExists(size_t id) const;
  bool chatExists(size_t id) const;

  const std::vector<std::string> &history() const;
  std::vector<std::string> chatLog(size_t chatId) const;

  boost::asio::strand<boost::asio::io_context::executor_type> getStrand();

private:
  void applySql(const std::string &sql);

  boost::asio::strand<boost::asio::io_context::executor_type> _strand;

  std::unordered_map<size_t, std::string> _users;
  std::unordered_map<size_t, std::string> _chats;
  std::unordered_map<size_t, std::vector<std::string>> _messages;
  std::vector<std::string> _history;
};
