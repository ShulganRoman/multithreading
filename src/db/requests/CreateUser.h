#pragma once

#include "IRequest.h"
#include <format>
#include <string>

class CreateUser : public IRequest {
public:
  CreateUser(const std::string &username, const std::string password)
      : _username(username), _password(password) {}

  std::string getRequest() const override {
    return std::format("INSERT INTO users (name, password) VALUES ('{}', '{}') "
                       "ON CONFLICT (name) DO NOTHING RETURNING id;",
                       _username, _password);
  }

private:
  std::string _username;
  std::string _password;
};
