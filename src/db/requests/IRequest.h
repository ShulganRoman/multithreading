#pragma once

#include <string>

class IRequest {
public:
  virtual ~IRequest() = default;
  virtual std::string getRequest() const = 0;
};
