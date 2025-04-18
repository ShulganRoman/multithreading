#include "IServer.h"
#include "IUser.h"
#include "InvalidDeleteUser.h"
#include <utility>

void IServer::create_user(IUser &user) {
  _users.insert(std::make_pair(user.getId(), std::move(user)));
}

void IServer::delete_user(size_t id) {
  if (_users.find(id) == _users.end()) {
    throw UsernameException(id);
    return;
  }

  auto expected = _users[id];

  _users.erase(id);
}

const std::unordered_map<size_t, IUser> &IServer::get_users() const {
  return _users;
}
