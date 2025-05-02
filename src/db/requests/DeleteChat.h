#pragma once

#include "IRequest.h"
#include <format>

class DeleteChat : public IRequest {
public:
  explicit DeleteChat(size_t id) : _id(id) {}

  std::string getRequest() const override {
    return std::format("DELETE FROM chats WHERE id = {};", _id);
  }

private:
  size_t _id;
};
