#include "TestUser.h"
#include <gtest/gtest.h>

class TestUserTest : public ::testing::Test {
protected:
  void SetUp() override { TestUser::reset(); }
};

TEST_F(TestUserTest, NameConstructorAssignsNameAndIncrementsId) {
  TestUser u("Alice");
  EXPECT_EQ(u.getName(), "Alice");
  EXPECT_EQ(u.getId(), 1u);

  TestUser v("Bob");
  EXPECT_EQ(v.getName(), "Bob");
  EXPECT_EQ(v.getId(), 2u);
}

TEST_F(TestUserTest, CopyConstructorCopiesNameAndId) {
  TestUser u("Alice");
  auto originalId = u.getId();
  TestUser copy(u);
  EXPECT_EQ(copy.getName(), "Alice");
  EXPECT_EQ(copy.getId(), originalId);

  TestUser another("Charlie");
  EXPECT_EQ(another.getId(), originalId + 1u);
}

TEST_F(TestUserTest, MoveConstructorMovesNameAndCopiesId) {
  TestUser u("Alice");
  auto originalId = u.getId();
  TestUser moved(std::move(u));
  EXPECT_EQ(moved.getName(), "Alice");
  EXPECT_EQ(moved.getId(), originalId);
}

TEST_F(TestUserTest, CopyAssignmentCopiesNameAndId) {
  TestUser u("Alice");
  TestUser v("Bob");
  auto bobId = v.getId();

  v = u;
  EXPECT_EQ(v.getName(), "Alice");
  EXPECT_EQ(v.getId(), u.getId());

  TestUser w("Charlie");
  EXPECT_EQ(w.getId(), bobId + 1u);
}

TEST_F(TestUserTest, CopyAssignmentSelfAssignment) {
  TestUser u("Alice");
  auto id = u.getId();
  u = u;
  EXPECT_EQ(u.getName(), "Alice");
  EXPECT_EQ(u.getId(), id);
}

TEST_F(TestUserTest, MoveAssignmentMovesNameAndCopiesId) {
  TestUser u("Alice");
  TestUser v("Bob");
  auto aliceId = u.getId();
  v = std::move(u);
  EXPECT_EQ(v.getName(), "Alice");
  EXPECT_EQ(v.getId(), aliceId);
}

TEST_F(TestUserTest, ResetStaticCounter) {
  TestUser u1("Alice");
  EXPECT_EQ(u1.getId(), 1u);
  TestUser u2("Bob");
  EXPECT_EQ(u2.getId(), 2u);

  TestUser::reset();
  TestUser u3("Charlie");
  EXPECT_EQ(u3.getId(), 1u);
}
