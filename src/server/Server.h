#pragma once

#include "IServer.h"

class Server : public IServer {
private:
  static Server *_instance;
  Server()
      : _database("dbname=multithreading user=romansulgan "
                  "password='[jxe,snmvjkjlsv' host=localhost") {}

public:
  static Server *getInstance();

private:
  Database _database;
};
