#include "../src/server/TestServer.h"
#include <atomic>
// #include <boost/test/minimal.hpp>
#include <iostream>

std::atomic<size_t> TestUser::userId{0};

int main() {
  TestServer s;

  s.create_user("s1"); // 1
  s.create_user("s2"); // 2
  s.create_user("s1"); // 3
  s.reset();
  s.create_user("s1"); // 1
  s.create_user("s2"); // 2
  s.create_user("s1"); // 3

  auto users = *s.get_users();

  for (auto user : users) {
    std::cout << user.second.getName() << ' ';
    std::cout << user.second.getId() << std::endl;
  }
}
