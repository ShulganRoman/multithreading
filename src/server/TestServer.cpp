#include "TestServer.h"
#include "InvalidDeleteUser.h"
#include "TestUser.h"
#include <cstddef>
#include <unordered_map>

void TestServer::create_user(std::string name) {
  auto newUser = TestUser(name);
  _users[newUser.getId()] = newUser;
}

void TestServer::delete_user(std::string name, size_t id) {
  if (_users.find(id) == _users.end()) {
    throw UsernameException(id);
    return;
  }

  auto expected = _users[id];

  if (expected.getName() != name) {
    throw UsernameException(name, expected.getName(), id);
    return;
  }

  _users.erase(id);
}

void TestServer::reset() {
  _users.clear();
  TestUser::reset();
}

const std::unordered_map<size_t, TestUser> *TestServer::get_users() {
  return &_users;
}
