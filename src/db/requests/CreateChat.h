#pragma once

#include "IChat.h"
#include "IRequest.h"
#include <format>

class CreateChat : public IRequest {
public:
  CreateChat(std::shared_ptr<IChat> chat) : _chat(std::move(chat)) {}
  string buildRequest() override {
    return std::format(R"(
                  INSERT INTO "chat" (id, name)
                  VALUES ({}, '{}');
                  )",
                       _chat->getId(), _chat->getName());
  }

private:
  std::shared_ptr<IChat> _chat;
};
