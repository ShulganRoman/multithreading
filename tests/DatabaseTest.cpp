#include "Database.h"
#include "TestChat.h"
#include "TestUser.h"
#include "requests/CreateChat.h"
#include "requests/CreateUser.h"
#include "requests/PushMessageFromUserInChat.h"
#include <gtest/gtest.h>
#include <memory>

class ServerTestingClass : public ::testing::Test {
protected:
  ServerTestingClass()
      : db("dbname=multithreading user=romansulgan password = "
           "'[jxe,snmvjkjlsv' "
           "host=localhost") {}

  void SetUp() override {}
  void TearDown() override {}

  Database db;
};

TEST_F(ServerTestingClass, AddSingleUser) {
  auto user = std::make_shared<TestUser>("TestUser_0");
  db.push_request(std::make_unique<CreateUser>(user));
  db.execQuery();

  auto result =
      db.tx().exec("SELECT name FROM \"user\" WHERE name = 'TestUser_0';");
  ASSERT_EQ(result.size(), 1);
  EXPECT_EQ(result[0]["name"].as<std::string>(), "TestUser_0");
}

TEST_F(ServerTestingClass, AddChat) {
  auto chat = std::make_shared<TestChat>("test group");
  db.push_request(std::make_unique<CreateChat>(chat));
  db.execQuery();

  auto result =
      db.tx().exec("SELECT name FROM \"chat\" WHERE name = 'test group';");
  ASSERT_EQ(result.size(), 1);
  EXPECT_EQ(result[0]["name"].as<std::string>(), "test group");
}

TEST_F(ServerTestingClass, PushMessage) {
  auto user = make_shared<TestUser>("User_X");
  auto chat = make_shared<TestChat>("Chat_X");

  db.push_request(std::make_unique<CreateUser>(user));
  db.push_request(std::make_unique<CreateChat>(chat));
  db.execAndClear();

  std::string message = "Hello world";
  db.push_request(std::make_unique<PushMessageFromUserInChat>(
      message, user->getId(), chat->getId()));
  db.execQuery();

  auto result =
      db.tx().exec("SELECT message FROM \"message\" WHERE user_id = " +
                   std::to_string(user->getId()) + ";");
  ASSERT_EQ(result.size(), 1);
  EXPECT_EQ(result[0]["message"].as<std::string>(), message);
}

TEST_F(ServerTestingClass, TransactionAbort) {
  auto user = make_shared<TestUser>("AbortUser");
  db.push_request(std::make_unique<CreateUser>(user));
  db.execQuery();
  db.abort(); // явно откатываем

  auto result =
      db.tx().exec("SELECT * FROM \"user\" WHERE name = 'AbortUser';");
  EXPECT_EQ(result.size(), 0); // записи быть не должно
}

TEST_F(ServerTestingClass, AddManyUsers) {
  const int N = 5;
  for (int i = 0; i < N; ++i) {
    auto user = make_shared<TestUser>("User_" + std::to_string(i));
    db.push_request(std::make_unique<CreateUser>(user));
  }

  db.execQuery();

  auto result = db.tx().exec("SELECT COUNT(*) FROM \"user\";");
  int count = result[0][0].as<int>();
  EXPECT_GE(count, N); // в базе должно быть хотя бы N пользователей
}

TEST_F(ServerTestingClass, EmptyAtStart) {
  auto result = db.tx().exec("SELECT COUNT(*) FROM \"user\";");
  EXPECT_EQ(result[0][0].as<int>(), 0);
}
