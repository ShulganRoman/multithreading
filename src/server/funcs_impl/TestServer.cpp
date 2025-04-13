#include "TestServer.h"
#include "TestUser.h"

void TestServer::reset() {
  _users.clear();
  TestUser::reset();
}
