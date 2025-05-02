#pragma once

#include "IRequest.h"
#include <format>

class InsertUserIntoChat : public IRequest {
public:
  InsertUserIntoChat(size_t userId, size_t chatId)
      : _userId(userId), _chatId(chatId) {}

  std::string getRequest() const override {
    return std::format(
        "INSERT INTO chat_users (chat_id, user_id) VALUES ({}, {});", _chatId,
        _userId);
  }

private:
  size_t _userId;
  size_t _chatId;
};
