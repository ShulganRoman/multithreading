#include "Server.h"
#include "../exceptions/InvalidDeleteUser.h"
#include <cstddef>
#include <unordered_map>

Server *Server::_instance = nullptr;

Server *Server::getInstance() {
  if (!_instance)
    return new Server();

  return _instance;
}

void Server::create_user(std::string name) {
  auto newUser = User(name);
  _users[newUser.getId()] = newUser;
}

void Server::delete_user(std::string name, size_t id) {
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

const std::unordered_map<size_t, User> *Server::get_users() { return &_users; }
