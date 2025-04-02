#include "User.h"
#include <utility>

std::atomic<size_t> User::userId{0};

User::User() = default;

User::User(std::string name) : _name(name), _id(++userId) {}
User::User(User &&other) : _name(std::move(other._name)), _id(other._id) {}
User::User(const User &other) : _name(other._name), _id(other._id) {}

User &User::operator=(User &&other) {
  _name = std::move(other._name);
  _id = other._id;

  return *this;
}

User &User::operator=(const User &other) {
  if (&other == this)
    return *this;

  _name = other._name;
  _id = other._id;

  return *this;
}

User::~User() = default;

size_t User::getId() const { return _id; }
std::string User::getName() const { return _name; }
