#pragma once

#include <atomic>
#include <string>
class User {
public:
  User();
  User(std::string name);
  User(User &&);
  User(const User &);
  User &operator=(User &&);
  User &operator=(const User &);
  ~User();

public:
  size_t getId() const;
  std::string getName() const;

private:
  static std::atomic<size_t> userId;

  size_t _id;
  std::string _name;
};
