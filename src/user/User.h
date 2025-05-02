#pragma once

#include "IUser.h"
#include <atomic>

class User : public IUser {
public:
  User() = delete;
  User(const std::string &);
  User(User &&);
  User(const User &);
  User &operator=(User &&);
  User &operator=(const User &);

private:
  static std::atomic<size_t> userId;
};
