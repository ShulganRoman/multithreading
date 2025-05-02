#pragma once

#include "IRequest.h"
#include <format>

class DeleteUser : public IRequest {
public:
  explicit DeleteUser(size_t id) : _id(id) {}

  std::string getRequest() const override {
    return std::format("DELETE FROM users WHERE id = {};", _id);
  }

private:
  size_t _id;
};
