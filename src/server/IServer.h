#pragma once

#include "IChat.h"
#include "IUser.h"
#include <unordered_map>

class IServer {
public:
  virtual ~IServer() = default;

  void create_user(IUser &user);
  void delete_user(size_t id);

  void create_chat(IChat &chat);
  void delete_chat(size_t id);

  // void insert_user_into_chat(IUser &user, IChat &chat);

  const std::unordered_map<size_t, IUser> &get_users() const;

protected:
  std::unordered_map<size_t, IUser> _users;
};

// virtual void create_chat();     // TODO: implement into server
// virtual void addUserIntoChat(); // TODO: implement into server
