#include "interpret_command.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "command_executor.h"
#include "object_mock.h"

using AllObjects = std::map<int, std::vector<Object *>>;

class InterpretCommandTest : public ::testing::Test {
 protected:
  AllObjects objects;
  std::unique_ptr<CommandExecutor> cmd_exec;

  void SetUp() override {
    cmd_exec = std::make_unique<CommandExecutor>();
    objects[1].push_back(new ObjectMock(123));
    objects[1].push_back(new ObjectMock(321));
    objects[2].push_back(new ObjectMock(987));
    objects[2].push_back(new ObjectMock(789));
  }
  void TearDown() override {
    for (auto &obj_vec : objects) {
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

  Object *obj = objects[msg.id_game_].at(0);
  ObjectMock *obj_mock = static_cast<ObjectMock *>(obj);
  EXPECT_CALL(*obj_mock, getProperty("id"))
      .WillRepeatedly(::testing::Return(123));

  obj = objects[msg.id_game_].at(1);
  obj_mock = static_cast<ObjectMock *>(obj);
  EXPECT_CALL(*obj_mock, getProperty("id"))
      .WillRepeatedly(::testing::Return(321));

  obj = objects[2].at(0);
  obj_mock = static_cast<ObjectMock *>(obj);
  EXPECT_CALL(*obj_mock, getProperty("id"))
      .WillRepeatedly(::testing::Return(987));

  obj = objects[2].at(1);
  obj_mock = static_cast<ObjectMock *>(obj);
  EXPECT_CALL(*obj_mock, getProperty("id"))
      .WillRepeatedly(::testing::Return(789));

  InterpretCommand inter_cmd(msg, &objects, cmd_exec.get());
  ASSERT_NO_THROW(inter_cmd.execute());
  EXPECT_EQ(1, cmd_exec->countCommandInQueue());
}

TEST_F(InterpretCommandTest, failed_move_command) {
  TMessage msg;
  msg.id_game_ = 1;
  msg.id_game_obj_ = 789;
  msg.id_operation_ = 2;
  msg.args_json_ = {2, 45};

  Object *obj = objects[msg.id_game_].at(0);
  ObjectMock *obj_mock = static_cast<ObjectMock *>(obj);
  EXPECT_CALL(*obj_mock, getProperty("id"))
      .WillRepeatedly(::testing::Return(123));

  obj = objects[msg.id_game_].at(1);
  obj_mock = static_cast<ObjectMock *>(obj);
  EXPECT_CALL(*obj_mock, getProperty("id"))
      .WillRepeatedly(::testing::Return(321));

  obj = objects[2].at(0);
  obj_mock = static_cast<ObjectMock *>(obj);
  EXPECT_CALL(*obj_mock, getProperty("id"))
      .WillRepeatedly(::testing::Return(987));

  obj = objects[2].at(1);
  obj_mock = static_cast<ObjectMock *>(obj);
  EXPECT_CALL(*obj_mock, getProperty("id"))
      .WillRepeatedly(::testing::Return(789));

  InterpretCommand inter_cmd(msg, &objects, cmd_exec.get());
  ASSERT_NO_THROW(inter_cmd.execute());
  EXPECT_EQ(0, cmd_exec->countCommandInQueue());
}


TEST_F(InterpretCommandTest, add_rotate_command) {
  TMessage msg;
  msg.id_game_ = 2;
  msg.id_game_obj_ = 789;
  msg.id_operation_ = 2;
  msg.args_json_ = {2, 45};

  Object *obj = objects[msg.id_game_].at(0);
  ObjectMock *obj_mock = static_cast<ObjectMock *>(obj);
  EXPECT_CALL(*obj_mock, getProperty("id"))
      .WillRepeatedly(::testing::Return(123));

  obj = objects[msg.id_game_].at(1);
  obj_mock = static_cast<ObjectMock *>(obj);
  EXPECT_CALL(*obj_mock, getProperty("id"))
      .WillRepeatedly(::testing::Return(321));

  obj = objects[2].at(0);
  obj_mock = static_cast<ObjectMock *>(obj);
  EXPECT_CALL(*obj_mock, getProperty("id"))
      .WillRepeatedly(::testing::Return(987));

  obj = objects[2].at(1);
  obj_mock = static_cast<ObjectMock *>(obj);
  EXPECT_CALL(*obj_mock, getProperty("id"))
      .WillRepeatedly(::testing::Return(789));

  InterpretCommand inter_cmd(msg, &objects, cmd_exec.get());
  ASSERT_NO_THROW(inter_cmd.execute());
  EXPECT_EQ(1, cmd_exec->countCommandInQueue());
}