#include <gtest/gtest.h>

// #define BOOST_TEST_MAIN
// #define BOOST_TEST_DYN_LIN
// #include <boost/test/included/unit_test.hpp>
//
// #include "../src/server/TestSErver.h"
// #include "../src/user/TestUser.h"
//
// std::atomic<size_t> TestUser::userId{0};
//
// struct Fixture {
//   TestServer server;
//   std::unordered_map<size_t, TestUser> list;
//   Fixture() {
//     server.create_user("Roman");
//     server.create_user("Danil");
//     server.create_user("Lubov");
//     server.create_user("Vasiliy");
//     server.create_user("Polina");
//     server.create_user("Alice");
//     server.create_user("Bob");
//
//     list = *server.get_users();
//   }
// };
//
// BOOST_FIXTURE_TEST_SUITE(ServerTest, Fixture)
//
// BOOST_FIXTURE_TEST_CASE(Addition, Fixture) {
//   BOOST_REQUIRE(list[1].getName() == "Roman");
//   BOOST_REQUIRE(list[1].getId() == 1);
//   BOOST_REQUIRE(list[2].getName() == "Danil");
//   BOOST_REQUIRE(list[2].getId() == 2);
//   BOOST_REQUIRE(list[3].getName() == "Lubov");
//   BOOST_REQUIRE(list[3].getId() == 3);
//   BOOST_REQUIRE(list[4].getName() == "Vasiliy");
//   BOOST_REQUIRE(list[4].getId() == 4);
//   BOOST_REQUIRE(list[5].getName() == "Polina");
//   BOOST_REQUIRE(list[5].getId() == 5);
//   BOOST_REQUIRE(list[6].getName() == "Alice");
//   BOOST_REQUIRE(list[6].getId() == 6);
//   BOOST_REQUIRE(list[7].getName() == "Bob");
//   BOOST_REQUIRE(list[7].getId() == 7);
// }
//
// BOOST_FIXTURE_TEST_CASE(Deleting, Fixture) {
//   BOOST_REQUIRE(list[1].getName() == "Roman");
//   BOOST_REQUIRE(list[1].getId() == 1);
// }
//
// //   SECTION("Ошибка при удалении: неверное имя пользователя") {
// //     try {
// //       REQUIRE_THROWS_AS(testServer.delete_user("Luba", 3),
// //       UsernameException);
// //     } catch (const UsernameException &ex) {
// //       std::string expected =
// //           "Exception: name Luba not match with userName Lubov witch has
// id 3.
// //           ";
// //           REQUIRE(std::string(ex.what()) == expected);
// //     }
// //   }
// //
// //   SECTION("Ошибка при удалении: несуществующий пользователь") {
// //     REQUIRE(userList[1].getName() == "Roman");
// //     REQUIRE(userList[1].getId() == 1);
// //     REQUIRE(userList[2].getName() == "Danil");
// //     REQUIRE(userList[2].getId() == 2);
// //     REQUIRE(userList[3].getName() == "Lubov");
// //     REQUIRE(userList[3].getId() == 3);
// //
// //     testServer.delete_user("Polina", 5);
// //
// //     try {
// //       REQUIRE_THROWS_AS(testServer.delete_user("Polina", 5),
// //       UsernameException);
// //     } catch (const UsernameException &ex) {
// //       REQUIRE(std::string(ex.what()) == "Exception: user with id 5 not
// //       found.");
// //     }
// //   }
// //
// //   SECTION("Множественное удаление и повторное добавление") {
// //     int aliceId = -1, bobId = -1;
// //
// //     for (const auto &pair : userList) {
// //       if (pair.second.getName() == "Alice")
// //         aliceId = pair.second.getId();
// //       if (pair.second.getName() == "Bob")
// //         bobId = pair.second.getId();
// //     }
// //
// //     REQUIRE(aliceId != -1);
// //     REQUIRE(bobId != -1);
// //
// //     testServer.delete_user("Bob", bobId);
// //     userList = *testServer.get_users();
// //
// //     REQUIRE(userList.find(bobId) == userList.end());
// //
// //     testServer.create_user("Bob");
// //     userList = *testServer.get_users();
// //
// //     int newBobId = -1;
// //
// //     for (const auto &pair : userList) {
// //       if (pair.second.getName() == "Bob" && pair.second.getId() != bobId)
// {
// //         newBobId = pair.second.getId();
// //         break;
// //       }
// //     }
// //
// //     REQUIRE(newBobId > bobId);
// //   }
// // }
// BOOST_AUTO_TEST_SUITE_END()
