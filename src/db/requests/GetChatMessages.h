#pragma once

#include "IRequest.h"
#include <format>
#include <string>

class GetChatMessages : public IRequest {
public:
  explicit GetChatMessages(std::size_t chatId) : _chatId(chatId) {}

  std::string getRequest() const override {
    return std::format("SELECT users.name, messages.content "
                       "FROM   messages "
                       "JOIN   users ON users.id = messages.user_id "
                       "WHERE  messages.chat_id = {} "
                       "ORDER  BY messages.id;",
                       _chatId);
  }

private:
  std::size_t _chatId;
};
