#pragma once

#include <string>
class IUser {
public:
  virtual ~IUser() = default;

  const size_t getId() const;
  std::string getName() const;

protected:
  size_t _id;
  std::string _name;
};
