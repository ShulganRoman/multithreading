#pragma once

#include "IUser.h"
#include <atomic>
#include <string>

class TestUser : public IUser {
public:
  TestUser() = delete;
  TestUser(const std::string &name);
  TestUser(TestUser &&);
  TestUser(const TestUser &);
  TestUser &operator=(TestUser &&);
  TestUser &operator=(const TestUser &);

  static void reset();

private:
  static std::atomic<size_t> userId;
};
