#pragma once

#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

class MessageBuffer {
public:
  MessageBuffer(const std::string &data) : data_(data) { deserialize(); }

  void setUsername(const std::string &username) {
    metadata_["username"] = username;
  }

  void setId(int id) { metadata_["id"] = id; }

  void setDatetime(const std::string &datetime) {
    metadata_["datetime"] = datetime;
  }

  void setMessage(const std::string &message) { message_ = message; }

  std::string getUsername() const { return metadata_["username"]; }

  int getId() const { return metadata_["id"]; }

  std::string getDatetime() const { return metadata_["datetime"]; }

  std::string getMessage() const { return message_; }

  void serialize() {
    // TODO:
  }

  void deserialize() {
    json fullMessage = json::parse(data_);

    metadata_ = fullMessage["metadata"];
    message_ = fullMessage["message"];
  }

private:
  std::string data_;
  json metadata_;
  std::string message_;
};
