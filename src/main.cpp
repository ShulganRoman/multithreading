#include "IUser.h"
#include "Server.h"
#include "TestServer.h"
#include "TestUser.h"
#include "User.h"
#include <iostream>
#include <unordered_map>

void printUsers(const std::unordered_map<size_t, IUser> *users) {
  for (auto p : *users)
    std::cout << "id: " << p.first << ", name: " << p.second.getName().c_str()
              << '\n';
}

int main() {
  auto server = Server::getInstance();
  auto test = TestServer();

  auto *users = server->get_users();
  auto test_users = test.get_users();

  User u1("Roman");
  User u2("Danil");
  User u3("Vasiliy");
  User u4("Lubov");

  server->create_user(u1);
  server->create_user(u2);
  server->create_user(u3);
  server->create_user(u4);

  TestUser tu1("Roman");
  TestUser tu2("Danil");
  TestUser tu3("Vasiliy");
  TestUser tu4("Lubov");

  test.create_user(tu1);
  test.create_user(tu2);
  test.create_user(tu3);
  test.create_user(tu4);

  printUsers(users);
  printUsers(test_users);

  test.reset();

  tu1 = {"Roman"};
  tu2 = {"Danil"};
  tu3 = {"Vasiliy"};
  tu4 = {"Lubov"};

  test.create_user(tu1);
  test.create_user(tu2);
  test.create_user(tu3);
  test.create_user(tu4);

  printUsers(test_users);
}
