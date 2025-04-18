#pragma once

#include "IRequest.h"
#include <format>
#include <string>

class PushMessageFromUserInChat : public IRequest {
public:
  PushMessageFromUserInChat(const string &message, size_t userId, size_t chatId)
      : _message(message), _chatId(chatId), _userId(userId) {}
  string buildRequest() override {
    return std::format(R"(
                  INSERT INTO "message" (chat_id, user_id, message)
                  VALUES ({}, {}, '{}');
                  )",
                       _chatId, _userId, _message);
  }

private:
  string _message;
  size_t _userId;
  size_t _chatId;
};
