#pragma once

#include "TestUser.h"
#include <atomic>
#include <string>

class TestUser {
public:
  TestUser() = default;

  TestUser(std::string name) : _name(name), _id(++userId) {}
  TestUser(TestUser &&other) : _name(std::move(other._name)), _id(other._id) {}
  TestUser(const TestUser &other) : _name(other._name), _id(other._id) {}

  TestUser &operator=(TestUser &&other) {
    _name = std::move(other._name);
    _id = other._id;

    return *this;
  }

  TestUser &operator=(const TestUser &other) {
    if (&other == this)
      return *this;

    _name = other._name;
    _id = other._id;

    return *this;
  }

  ~TestUser() = default;

private:
  static std::atomic<size_t> userId;

  std::string _name;
  size_t _id;

public:
  static void reset() { userId = 0; }

  size_t getId() const { return _id; }
  std::string getName() const { return _name; }
};

// TODO: вынести реализацию в отдельный файл и подумать как это можно
// сократить чтобы не дублировать
