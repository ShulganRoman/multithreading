#pragma once

#include "IRequest.h"
#include "IUser.h"
#include <format>

using namespace std;

class CreateUser : public IRequest {
public:
  CreateUser(std::shared_ptr<IUser> user) : _user(std::move(user)) {}
  string buildRequest() override {
    return std::format(R"(
                  INSERT INTO "user" (id, name)
                  VALUES ({}, '{}');
                  )",
                       _user->getId(), _user->getName());
  }

private:
  std::shared_ptr<IUser> _user;
};
