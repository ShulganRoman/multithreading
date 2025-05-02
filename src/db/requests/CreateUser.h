#pragma once

#include "IRequest.h"
#include <format>
#include <string>

class CreateUser : public IRequest {
public:
  CreateUser(size_t id, const std::string &name) : _id(id), _name(name) {}

  std::string getRequest() const override {
    return std::format("INSERT INTO users (id, name) VALUES ({}, '{}');", _id,
                       _name);
  }

private:
  size_t _id;
  std::string _name;
};
