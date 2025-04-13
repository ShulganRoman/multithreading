#pragma once

#include "IServer.h"

class Server : public IServer {
private:
  static Server *_instance;
  Server() = default;

public:
  static Server *getInstance();

private:
  // static std::atomic<unsigned long> _chatId; // TODO: move _userId
};
