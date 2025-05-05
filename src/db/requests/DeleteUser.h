#pragma once

#include "IRequest.h"
#include <format>

class DeleteUser : public IRequest {
public:
  explicit DeleteUser(std::string username) : username_(username) {}

  std::string getRequest() const override {
    return std::format("DELETE FROM users WHERE name = '{}';", username_);
  }

private:
  std::string username_;
};
