#pragma once

#include "IRequest.h"
#include <format>
#include <string>

class FindUsers : public IRequest {
public:
  FindUsers(const std::string &username, const std::string &me)
      : _username(username), _me(me) {}

  std::string getRequest() const override {
    return std::format("SELECT name FROM users WHERE LOWER(name) LIKE '{}%' "
                       "AND name NOT ILIKE '{}';",
                       _username, _me);
  }

private:
  std::string _username;
  std::string _me;
};
