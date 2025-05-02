#include "TestChat.h"
#include <gtest/gtest.h>

class TestChatTest : public ::testing::Test {
protected:
  void SetUp() override { TestChat::reset(); }
};

TEST_F(TestChatTest, NameConstructorAssignsNameAndIncrementsId) {
  TestChat c1("General");
  EXPECT_EQ(c1.getName(), "General");
  EXPECT_EQ(c1.getId(), 1u);

  TestChat c2("Random");
  EXPECT_EQ(c2.getName(), "Random");
  EXPECT_EQ(c2.getId(), 2u);
}

TEST_F(TestChatTest, CopyConstructorCopiesNameAndId) {
  TestChat c1("General");
  auto originalId = c1.getId();
  TestChat copy(c1);
  EXPECT_EQ(copy.getName(), "General");
  EXPECT_EQ(copy.getId(), originalId);

  TestChat c2("Random");
  EXPECT_EQ(c2.getId(), originalId + 1u);
}

TEST_F(TestChatTest, MoveConstructorMovesNameAndCopiesId) {
  TestChat c1("General");
  auto originalId = c1.getId();
  TestChat moved(std::move(c1));
  EXPECT_EQ(moved.getName(), "General");
  EXPECT_EQ(moved.getId(), originalId);
}

TEST_F(TestChatTest, CopyAssignmentCopiesNameAndId) {
  TestChat c1("General");
  TestChat c2("Random");
  auto randomId = c2.getId();

  c2 = c1;
  EXPECT_EQ(c2.getName(), "General");
  EXPECT_EQ(c2.getId(), c1.getId());

  TestChat c3("Private");
  EXPECT_EQ(c3.getId(), randomId + 1u);
}

TEST_F(TestChatTest, CopyAssignmentSelfAssignment) {
  TestChat c1("General");
  auto id = c1.getId();
  c1 = c1;
  EXPECT_EQ(c1.getName(), "General");
  EXPECT_EQ(c1.getId(), id);
}

TEST_F(TestChatTest, MoveAssignmentMovesNameAndCopiesId) {
  TestChat c1("General");
  TestChat c2("Random");
  auto generalId = c1.getId();
  c2 = std::move(c1);
  EXPECT_EQ(c2.getName(), "General");
  EXPECT_EQ(c2.getId(), generalId);
}

TEST_F(TestChatTest, ResetStaticCounter) {
  TestChat c1("General");
  EXPECT_EQ(c1.getId(), 1u);
  TestChat c2("Random");
  EXPECT_EQ(c2.getId(), 2u);

  TestChat::reset();
  TestChat c3("Private");
  EXPECT_EQ(c3.getId(), 1u);
}
