#pragma once
#include "IRequest.h"
#include <format>
#include <string>

class AddMessage : public IRequest {
public:
  AddMessage(size_t chatId, size_t userId, const std::string &text)
      : _chatId(chatId), _userId(userId), _text(text) {}

  std::string getRequest() const override {
    return std::format("INSERT INTO messages (chat_id, user_id, content) "
                       "VALUES ({}, {}, '{}');",
                       _chatId, _userId, _text);
  }

private:
  size_t _chatId;
  size_t _userId;
  std::string _text;
};
