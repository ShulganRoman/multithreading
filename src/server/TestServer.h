#pragma once

#include "../user/TestUser.h"
#include "IServer.h"
#include <unordered_map>

class TestServer : private IServer {
public:
  TestServer() = default;

  void create_user(std::string name) override;
  void delete_user(std::string name, size_t id) override;
  void reset();

  const std::unordered_map<size_t, TestUser> *get_users();

private:
  std::unordered_map<size_t, TestUser> _users;
};
