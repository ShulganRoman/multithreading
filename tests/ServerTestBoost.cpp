#include "../src/exceptions/InvalidDeleteUser.h"
#include "../src/server/TestServer.h"
#include "../src/user/TestUser.h"

#include <cstdio>
#include <gtest/gtest.h>
#include <unordered_map>

std::atomic<size_t> TestUser::userId{0};

class ServerTestingClass : public ::testing::Test {
protected:
  void SetUp() override {
    server.create_user("Roman");
    server.create_user("Danil");
    server.create_user("Lubov");
    server.create_user("Vasiliy");
    server.create_user("Polina");
    server.create_user("Alice");
    server.create_user("Bob");

    list = server.get_users();
  }

  void TearDown() override { server.reset(); }

  TestServer server;
  const std::unordered_map<size_t, TestUser> *list;
};

TEST_F(ServerTestingClass, Addition) {
  EXPECT_EQ(list->find(1)->second.getName(), "Roman");
  EXPECT_EQ(list->find(1)->second.getId(), 1);
  EXPECT_EQ(list->find(2)->second.getName(), "Danil");
  EXPECT_EQ(list->find(2)->second.getId(), 2);
  EXPECT_EQ(list->find(3)->second.getName(), "Lubov");
  EXPECT_EQ(list->find(3)->second.getId(), 3);
  EXPECT_EQ(list->find(4)->second.getName(), "Vasiliy");
  EXPECT_EQ(list->find(4)->second.getId(), 4);
  EXPECT_EQ(list->find(5)->second.getName(), "Polina");
  EXPECT_EQ(list->find(5)->second.getId(), 5);
  EXPECT_EQ(list->find(6)->second.getName(), "Alice");
  EXPECT_EQ(list->find(6)->second.getId(), 6);
  EXPECT_EQ(list->find(7)->second.getName(), "Bob");
  EXPECT_EQ(list->find(7)->second.getId(), 7);
}

TEST_F(ServerTestingClass, ExceptionDetection) {
  try {
    EXPECT_THROW(server.delete_user("Luba", 3), UsernameException);
  } catch (const UsernameException &ex) {
    std::string expected =
        "Exception: name Luba not match with userName Lubov witch hasid 3.";
    EXPECT_STREQ(ex.what(), expected.c_str());
  }
}

TEST_F(ServerTestingClass, Deleting) {
  server.delete_user("Polina", 5);

  try {
    EXPECT_THROW(server.delete_user("Polina", 5), UsernameException);
  } catch (const UsernameException &ex) {
    std::string expected = "Excetion: user with id 5 not found.";
    EXPECT_STREQ(ex.what(), expected.c_str());
  }

  EXPECT_EQ(server.get_users()->size(), 6);
}

TEST_F(ServerTestingClass, reindexingUser) {
  int aliceId = -1, bobId = -1;

  for (const auto &pair : *list) {
    if (pair.second.getName() == "Alice")
      aliceId = pair.second.getId();
    if (pair.second.getName() == "Bob")
      bobId = pair.second.getId();
  }

  EXPECT_TRUE(aliceId != -1);
  EXPECT_TRUE(bobId != -1);

  server.delete_user("Bob", bobId);

  EXPECT_TRUE(list->find(bobId) == list->end());

  server.create_user("Bob");

  int newBobId = -1;

  for (const auto &pair : *list) {
    if (pair.second.getName() == "Bob") {
      newBobId = pair.second.getId();
      break;
    }
  }

  // EXPECT_TRUE(newBobId > bobId);
}
