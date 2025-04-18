#pragma once

#include "IChat.h"
#include <atomic>

class Chat : public IChat {
public:
  Chat();
  Chat(const std::string &);
  Chat(Chat &&);
  Chat(const Chat &);
  Chat &operator=(Chat &&);
  Chat &operator=(const Chat &);

private:
  static std::atomic<size_t> chatId;
};
