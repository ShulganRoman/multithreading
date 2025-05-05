#pragma once

#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

class Buffer {
public:
  Buffer(const std::string &data) : data_(data) { deserialize(); }

  void serialize() {
    // TODO:
  }

  void deserialize() {
    json fullMessage = json::parse(data_);

    metadata_ = fullMessage["metadata"];
  }

  std::string getEntity() { return metadata_["entity"]; }

private:
  std::string data_;
  json metadata_;
};
