#pragma once

#include <format>
#include <string>

using namespace std;

class IRequest {
public:
  virtual string buildRequest() = 0;
  virtual ~IRequest() = default;

  static string restartId() {
    return format(R"(
      ALTER SEQUENCE user_id_seq RESTART WITH 1;
      ALTER SEQUENCE chat_id_seq RESTART WITH 1;
      ALTER SEQUENCE message_id_seq RESTART WITH 1;
                  )");
  }
};
