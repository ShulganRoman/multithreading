#include "Chat.h"

std::atomic<size_t> Chat::chatId = {0};

Chat::Chat(const std::string &name) {
  _name = name;
  _id = ++chatId;
}

Chat::Chat(Chat &&other) {
  _name = std::move(other._name);
  _id = other._id;
}

Chat::Chat(const Chat &other) {
  _name = other._name;
  _id = other._id;
}

Chat &Chat::operator=(Chat &&other) {
  _name = std::move(other._name);
  _id = other._id;

  return *this;
}

Chat &Chat::operator=(const Chat &other) {
  if (&other == this)
    return *this;

  _name = other._name;
  _id = other._id;

  return *this;
}
