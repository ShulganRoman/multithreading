#pragma once

#include "IChat.h"
#include <atomic>
#include <string>

class TestChat : public IChat {
public:
  TestChat();
  TestChat(const std::string &name);
  TestChat(TestChat &&);
  TestChat(const TestChat &);
  TestChat &operator=(TestChat &&);
  TestChat &operator=(const TestChat &);

  static void reset();

private:
  static std::atomic<size_t> chatId;
};
