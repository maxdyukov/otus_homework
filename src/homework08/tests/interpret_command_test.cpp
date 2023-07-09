#include "interpret_command.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "command_executor.h"
#include "object_mock.h"

// using AllObjects = std::map<int, std::vector<ObjectMock *>>;

class InterpretCommandTest : public ::testing::Test {
 protected:
  std::unique_ptr<std::map<int, std::vector<Object *>>> objects;
  std::unique_ptr<CommandExecutor> cmd_exec;

  void SetUp() override {
    objects = std::make_unique<std::map<int, std::vector<Object *>>>();
    cmd_exec = std::make_unique<CommandExecutor>();
    objects->operator[](1).push_back(new ObjectMock(123));
    objects->operator[](1).push_back(new ObjectMock(321));
    objects->operator[](2).push_back(new ObjectMock(987));
    objects->operator[](2).push_back(new ObjectMock(789));
  }
  void TearDown() override {
    for (auto &obj_vec : *objects) {
      for (auto obj : obj_vec.second) {
        delete obj;
      }
    }
  }
};

TEST_F(InterpretCommandTest, add_move_command) {
  TMessage msg;
  msg.id_game_ = 1;
  msg.id_game_obj_ = 321;
  msg.id_operation_ = 1;
  msg.args_json_ = {2};

  auto vec_obj = objects->at(msg.id_game_);
  EXPECT_CALL(*vec_obj[0], getProperty("id")).WillOnce(::testing::Return(123));
  EXPECT_CALL(*vec_obj[1], getProperty("id")).WillOnce(::testing::Return(123));
  auto vec_obj2 = objects->at(2);
  EXPECT_CALL(*vec_obj2[0], getProperty("id")).WillOnce(::testing::Return(987));
  EXPECT_CALL(*vec_obj2[1], getProperty("id")).WillOnce(::testing::Return(789));

  InterpretCommand inter_cmd(msg, objects.get(), cmd_exec.get());
  ASSERT_NO_THROW(inter_cmd.execute());
  EXPECT_EQ(1, cmd_exec->countCommandInQueue());
}