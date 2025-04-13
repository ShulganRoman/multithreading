#pragma once

#include "IUser.h"
#include <string>
#include <unordered_map>

class IServer {
public:
  virtual ~IServer() = default;

  void create_user(IUser &user);
  void delete_user(std::string name, size_t id);

  const std::unordered_map<size_t, IUser> *get_users();

protected:
  std::unordered_map<size_t, IUser> _users;
};

// virtual void create_chat();     // TODO: implement into server
// virtual void addUserIntoChat(); // TODO: implement into server
