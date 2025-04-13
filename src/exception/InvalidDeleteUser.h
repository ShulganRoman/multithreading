#pragma once

#include <exception>
#include <string>

class UsernameException
    : public std::exception { // TODO: decorator template maybe used by this
public:
  UsernameException(std::string wrongName, std::string expectedName, size_t id)
      : _wrongName(wrongName), _expectedName(expectedName), _id(id) {
    _message = "Exception: name " + _wrongName + " not match with userName " +
               _expectedName + " witch has id " + std::to_string(_id) + '.';
  }

  UsernameException(size_t id) : _id(id) {
    _message = "Exception: user with id " + std::to_string(_id) + " not found.";
  }

  const char *what() const _NOEXCEPT override;

private:
  std::string _message;
  std::string _wrongName;
  std::string _expectedName;
  size_t _id;
};

inline const char *UsernameException::what() const _NOEXCEPT {
  return _message.c_str();
}
