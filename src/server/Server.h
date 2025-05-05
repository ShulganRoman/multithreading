#pragma once

#include "AddMessage.h"
#include "Buffer.h"
#include "CreateChat.h"
#include "CreateUser.h"
#include "Database.h"
#include "FindUsers.h"
#include "GetChatMessages.h"
#include "GetUser.h"
#include "GetUserId.h"
#include "OpenChat.h"
#include "Session.h"
#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>

using boost::asio::ip::tcp;
using json = nlohmann::json;

inline std::string buildChatTitle(const std::string &a, const std::string &b) {
  return (a < b) ? a + " & " + b : b + " & " + a;
}

class Server {
public:
  static std::unique_ptr<Server> create(boost::asio::io_context &io,
                                        const std::string &db_conn,
                                        uint16_t port);

private:
  std::unordered_map<std::string, std::vector<std::weak_ptr<Session>>> clients_;

  Server(boost::asio::io_context &io, const std::string &db_conn, uint16_t port)
      : io_(io), acceptor_(io, tcp::endpoint(tcp::v4(), port)),
        database_(io_, db_conn) {
    std::cout << "Server listen " << port << '\n';
    accept();
  }

  void accept() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket sock) {
          if (!ec) {
            auto s = std::make_shared<Session>(
                std::move(sock),
                [this](std::shared_ptr<Session> sess, const std::string &msg) {
                  handle_request(sess, msg);
                });
            s->start();
          } else {
            std::cerr << "accept: " << ec.message() << '\n';
          }
          accept();
        });
  }

  void handle_request(std::shared_ptr<Session> session,
                      const std::string &msg) {
    json data = json::parse(msg);
    json meta = data["metadata"];

    if (meta["entity"] == "user") {
      size_t id = meta["id"];
      u_int8_t mode = data["mode"];
      if (mode == 0) {
        std::string username = data["modify"]["username"];
        std::string password = data["modify"]["password"];

        auto req = std::make_unique<CreateUser>(username, password);
        database_.execute(std::move(req), [session](pqxx::result res) {
          if (!res.empty())
            session->send("user_created\n");
          else
            session->send("username_taken\n");
        });
      } else if (mode == 1) {
        std::string username = data["modify"]["username"];
        std::string password = data["modify"]["password"];

        auto req = std::make_unique<GetUser>(username, password);
        database_.execute(std::move(req),
                          [this, session, username](pqxx::result res) {
                            if (res.empty())
                              session->send("incorrect_password_or_username\n");
                            else {
                              session->send("user_enter_success\n");

                              session->setUsername(username);
                              clients_[username].push_back(session);
                            }
                          });
      }
    } else if (meta["entity"] == "chat") {
      size_t id = meta["id"];
      std::string title = data["modify"]["title"];
      database_.execute(std::make_unique<CreateChat>(title));
    } else if (meta["entity"] == "message") {
      size_t id = meta["id"];
      size_t userId = meta["user_id"];
      size_t chatId = meta["chat_id"];
      std::string content = data["text"];
      database_.execute(std::make_unique<AddMessage>(chatId, userId, content));
    } else if (meta["entity"] == "find_users") {
      std::string username = meta["username"];
      std::string me = meta["self"];

      auto req = std::make_unique<FindUsers>(username, me);
      database_.execute(std::move(req), [session](pqxx::result res) {
        json j;

        if (!res.empty()) {
          for (const auto &row : res) {
            std::string name = row["name"].as<std::string>();
            j[name] = "";
          }
        }

        session->send(j.dump() + "\n");
      });
    } else if (meta["entity"] == "open_chat") {
      std::string fromUser = data["from"];
      std::string toUser = data["to"];
      std::string chatTitle = buildChatTitle(fromUser, toUser);

      database_.execute(std::make_unique<OpenChat>(chatTitle),
                        [this, session](pqxx::result cres) {
                          if (cres.empty()) {
                            session->send("chat_create_error\n");
                            return;
                          }
                          size_t chatId = cres[0]["id"].as<size_t>();

                          database_.execute(
                              std::make_unique<GetChatMessages>(chatId),
                              [session](pqxx::result rows) {
                                nlohmann::json j;
                                for (const auto &row : rows) {
                                  std::string user =
                                      row["name"].as<std::string>();
                                  std::string msg =
                                      row["content"].as<std::string>();
                                  j[user] = msg;
                                }
                                session->send(j.dump() + "\n");
                              });
                        });
    } else if (meta["entity"] == "send_message") {
      std::string fromUser = data["from"];
      std::string toUser = data["to"];
      std::string text = data["text"];

      std::string chatTitle = buildChatTitle(fromUser, toUser);

      database_.execute(
          std::make_unique<GetUserId>(fromUser),
          [this, session, chatTitle, text, fromUser,
           toUser](pqxx::result ures) {
            if (ures.empty()) {
              session->send("unknown_sender\n");
              return;
            }
            std::size_t userId = ures[0]["id"].as<std::size_t>();

            database_.execute(
                std::make_unique<OpenChat>(chatTitle),
                [this, session, userId, text, fromUser, toUser,
                 chatTitle](pqxx::result cres) {
                  if (cres.empty()) {
                    session->send("chat_create_error\n");
                    return;
                  }
                  std::size_t chatId = cres[0]["id"].as<std::size_t>();

                  database_.execute(
                      std::make_unique<AddMessage>(chatId, userId, text),
                      [this, session, fromUser, toUser, chatTitle,
                       text](pqxx::result) {
                        session->send("message_saved\n");

                        nlohmann::json push;
                        push["metadata"] = {{"entity", "chat_update"}};
                        push["from"] = fromUser;
                        push["chat"] = chatTitle;
                        push["text"] = text;
                        std::string raw = push.dump() + "\n";

                        auto it = clients_.find(toUser);
                        if (it != clients_.end()) {
                          auto &vec = it->second;
                          vec.erase(std::remove_if(
                                        vec.begin(), vec.end(),
                                        [](auto &w) { return w.expired(); }),
                                    vec.end());

                          for (auto &wp : vec)
                            if (auto target = wp.lock(); target)
                              target->send(raw);
                        }
                      });
                });
          });
    }
  }

  boost::asio::io_context &io_;
  tcp::acceptor acceptor_;
  Database database_;
};
