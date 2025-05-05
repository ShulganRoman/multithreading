#pragma once

#include "IRequest.h"
#include <format>
#include <string>

class GetUserId : public IRequest {
public:
  explicit GetUserId(const std::string &username) : _username(username) {}

  std::string getRequest() const override {
    return std::format("SELECT id FROM users WHERE name = '{}';", _username);
  }

private:
  std::string _username;
};
