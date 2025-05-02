#include "TestChat.h"
#include <atomic>

std::atomic<size_t> TestChat::chatId{0};

TestChat::TestChat(const std::string &name) {
  _name = name;
  _id = ++chatId;
}

TestChat::TestChat(TestChat &&other) {
  _name = std::move(other._name);
  _id = other._id;
}

TestChat::TestChat(const TestChat &other) {
  _name = other._name;
  _id = other._id;
}

TestChat &TestChat::operator=(TestChat &&other) {
  _name = std::move(other._name);
  _id = other._id;

  return *this;
}

TestChat &TestChat::operator=(const TestChat &other) {
  if (&other == this)
    return *this;

  _name = other._name;
  _id = other._id;

  return *this;
}

void TestChat::reset() { chatId = 0; }
