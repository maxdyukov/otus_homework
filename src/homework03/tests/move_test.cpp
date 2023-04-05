#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "move.h"
#include "movable_adapter.h"
#include "object_mock.h"

using namespace ::testing;

TEST(MoveTest, test1){
   ObjectMock v_object;
  EXPECT_CALL(v_object, getPosition()).WillRepeatedly(Return(std::vector<int>({12,5})));
}