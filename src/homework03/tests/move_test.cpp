#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "move.h"
#include "movable_adapter_mock.h"
#include "object_mock.h"

using namespace ::testing;

class MoveTest : public Test{
  protected:
  Object *object_;
  MovableAdapterMock *adapter_;
  MovableAdapterWithVelocityMock *adapter_with_velocity;
  virtual void SetUp() {
    object_ = new Object();
    adapter_ = new MovableAdapterMock(object_);
    adapter_with_velocity = new MovableAdapterWithVelocityMock(object_);
  }
  virtual void TearDown() {
    delete adapter_with_velocity;
    delete adapter_;
    delete object_;
  }
};

TEST_F(MoveTest, move_object) {
  EXPECT_CALL(*adapter_, getPosition())
      .WillOnce(Return(std::vector<int>({12, 5})));
  EXPECT_CALL(*adapter_, getVelocity())
      .WillOnce(Return(std::vector<int>({-7, 3})));

  Move move_command(adapter_);
  move_command.Execute();

  auto position = object_->getPosition();
  std::vector<int> result_position = {5, 8};

  for (int i = 0; i < position.size(); i++){
    EXPECT_EQ(result_position[i], position[i]);
  }
}

TEST_F(MoveTest, move_object_without_position){
  std::unique_ptr<MovableAdapter> adapter_without_mock = std::make_unique<MovableAdapter>(object_);

  Move move_command(adapter_without_mock.get());
  ASSERT_THROW(move_command.Execute(), std::invalid_argument);
}

TEST_F(MoveTest, move_object_without_velosity){
  EXPECT_CALL(*adapter_with_velocity, getPosition())
      .WillOnce(Return(std::vector<int>({12, 5})));

  Move move_command(adapter_with_velocity);
  ASSERT_THROW(move_command.Execute(), std::invalid_argument);
}

TEST_F(MoveTest, move_object_failed_set_position){
  EXPECT_CALL(*adapter_, getPosition())
      .WillOnce(Return(std::vector<int>({12, 5, 1})));
  EXPECT_CALL(*adapter_, getVelocity())
      .WillOnce(Return(std::vector<int>({-7, 3, 1})));

  Move move_command(adapter_);
  ASSERT_THROW(move_command.Execute(), std::runtime_error);
}