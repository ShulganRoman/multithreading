#pragma once

#include "IRequest.h"
#include <format>
#include <string>

class CreateChat : public IRequest {
public:
  CreateChat(const std::string &title) : _title(title) {}

  std::string getRequest() const override {
    return std::format("INSERT INTO chats (title) VALUES ('{}');", _title);
  }

private:
  std::string _title;
};
