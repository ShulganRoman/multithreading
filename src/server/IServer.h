#pragma once

#include <string>

class IServer {
public:
  virtual void create_user(std::string name) = 0;
  virtual void delete_user(std::string name, size_t id) = 0;
};

// virtual void create_chat();     // TODO: implement into server
// virtual void addUserIntoChat(); // TODO: implement into server
