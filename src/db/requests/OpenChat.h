#pragma once

#include "IRequest.h"
#include <format>
#include <string>

class OpenChat : public IRequest {
public:
  explicit OpenChat(const std::string &title) : _title(title) {}

  std::string getRequest() const override {
    return std::format("INSERT INTO chats (title) VALUES ('{}') "
                       "ON CONFLICT (title) "
                       "DO UPDATE SET title = EXCLUDED.title "
                       "RETURNING id;",
                       _title);
  }

private:
  std::string _title;
};
