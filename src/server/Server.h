#pragma once

#include "IServer.h"
#include "User.h"
#include <unordered_map>

class Server : private IServer {
private:
  static Server *_instance;
  Server() = default;

public:
  static Server *getInstance();

  void create_user(std::string name) override;
  void delete_user(std::string name, size_t id) override;

  const std::unordered_map<size_t, User> *get_users();

private:
  // static std::atomic<unsigned long> _chatId; // TODO: move _userId

  std::unordered_map<size_t, User> _users;
};
