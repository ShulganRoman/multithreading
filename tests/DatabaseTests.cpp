#include <boost/asio.hpp>
#include <future>
#include <gtest/gtest.h>
#include <thread>
#include <vector>

#include "TestDatabase.h"

#include "AddMessage.h"
#include "CreateChat.h"
#include "CreateUser.h"

class TestDBFixture : public ::testing::Test {
protected:
  TestDBFixture()
      : io(), work(boost::asio::make_work_guard(io)), db(io),
        ioThread([this] { io.run(); }) {}

  ~TestDBFixture() override {
    work.reset();
    ioThread.join();
  }

  std::string lastSql() {
    boost::asio::post(io, [this] { ready.set_value(); });
    ready.get_future().wait();
    ready = std::promise<void>{};
    EXPECT_FALSE(db.history().empty()) << "History is empty!";
    return db.history().back();
  }

  boost::asio::io_context io;
  boost::asio::executor_work_guard<boost::asio::io_context::executor_type> work;
  TestDatabase db;
  std::thread ioThread;
  std::promise<void> ready;
};

TEST_F(TestDBFixture, CreateUserSQL) {
  db.execute(std::make_unique<CreateUser>("Alice", "p"));
  EXPECT_EQ(lastSql(),
            "INSERT INTO users (name, password) VALUES ('Alice', 'p') "
            "ON CONFLICT (name) DO NOTHING RETURNING id;");
}

TEST_F(TestDBFixture, CreateChatSQL) {
  db.execute(std::make_unique<CreateChat>("General"));
  EXPECT_EQ(lastSql(), "INSERT INTO chats (title) VALUES ('General');");
}

TEST_F(TestDBFixture, AddMessageSQL) {
  db.execute(std::make_unique<AddMessage>(2, 9, "Hello!"));
  EXPECT_EQ(lastSql(), "INSERT INTO messages (chat_id, user_id, content) "
                       "VALUES (2, 9, 'Hello!');");
}

TEST(ThreadSafety, ConcurrentExecute) {
  boost::asio::io_context io;
  auto work = boost::asio::make_work_guard(io);
  TestDatabase db(io);
  std::thread ioThread([&] { io.run(); });

  constexpr size_t threads = 8;
  constexpr size_t perThread = 25;

  std::vector<std::thread> pool;

  for (size_t t = 0; t < threads; ++t) {
    pool.emplace_back([&db, t] {
      for (size_t i = 0; i < perThread; ++i) {
        db.execute(std::make_unique<CreateUser>("T" + std::to_string(t), ""));
      }
    });
  }

  for (auto &th : pool)
    th.join();

  std::promise<void> done;
  boost::asio::post(db.getStrand(), [&] { done.set_value(); });
  done.get_future().wait();

  EXPECT_EQ(db.history().size(), threads * perThread);

  work.reset();
  ioThread.join();
}

TEST(Async, ExecuteThroughThreadPool) {
  boost::asio::io_context io;
  auto work = boost::asio::make_work_guard(io);
  TestDatabase db(io);
  std::thread ioThread([&] { io.run(); });

  boost::asio::thread_pool tp(4);
  for (size_t i = 0; i < 100; ++i)
    db.execute(std::make_unique<CreateChat>("Chat" + std::to_string(i)));

  tp.join();

  std::promise<void> done;
  boost::asio::post(db.getStrand(), [&] { done.set_value(); });
  done.get_future().wait();

  EXPECT_EQ(db.history().size(), 100);
  EXPECT_EQ(db.history().front(),
            "INSERT INTO chats (title) VALUES ('Chat0');");
  EXPECT_EQ(db.history().back(),
            "INSERT INTO chats (title) VALUES ('Chat99');");

  work.reset();
  ioThread.join();
}
