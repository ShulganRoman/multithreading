#include "TestUser.h"
#include <atomic>

std::atomic<size_t> TestUser::userId{0};

TestUser::TestUser() = default;

TestUser::TestUser(const std::string &name) {
  _name = name;
  _id = ++userId;
}

TestUser::TestUser(TestUser &&other) {
  _name = std::move(other._name);
  _id = other._id;
}

TestUser::TestUser(const TestUser &other) {
  _name = other._name;
  _id = other._id;
}

TestUser &TestUser::operator=(TestUser &&other) {
  _name = std::move(other._name);
  _id = other._id;

  return *this;
}

TestUser &TestUser::operator=(const TestUser &other) {
  if (&other == this)
    return *this;

  _name = other._name;
  _id = other._id;

  return *this;
}

void TestUser::reset() { userId = 0; }
