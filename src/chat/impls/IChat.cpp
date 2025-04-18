#include "IChat.h"

const size_t &IChat::getId() const { return _id; }
const string &IChat::getName() const { return _name; }
const vector<string> &IChat::getMessages() const { return _messages; }
const unordered_set<size_t> &IChat::getUsersId() const { return _users; }
