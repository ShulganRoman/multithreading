#pragma once

#include "IRequest.h"
#include <format>
#include <string>

class GetUser : public IRequest {
public:
  GetUser(const std::string &username, const std::string &password)
      : _username(username), _password(password) {}

  std::string getRequest() const override {
    return std::format(
        "SELECT * FROM users WHERE name = '{}' and password = '{}'", _username,
        _password);
  }

private:
  std::string _username;
  std::string _password;
};
