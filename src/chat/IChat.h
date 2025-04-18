#pragma once

#include <cstddef>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class IChat {
public:
  virtual ~IChat() = default;

  const size_t &getId() const;
  const string &getName() const;
  const vector<string> &getMessages() const;
  const unordered_set<size_t> &getUsersId() const;

protected:
  size_t _id;
  string _name;
  vector<string> _messages;
  unordered_set<size_t> _users;
};
