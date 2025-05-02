#pragma once

#include "IRequest.h"
#include <format>
#include <string>

class CreateChat : public IRequest {
public:
  CreateChat(size_t id, const std::string &title) : _id(id), _title(title) {}

  std::string getRequest() const override {
    return std::format("INSERT INTO chats (id, title) VALUES ({}, '{}');", _id,
                       _title);
  }

private:
  size_t _id;
  std::string _title;
};
