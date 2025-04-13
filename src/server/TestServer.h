#pragma once

#include "IServer.h"

class TestServer : public IServer {
public:
  TestServer() = default;

  void reset();
};
