#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "rotate.h"
#include "rotable_adapter_mock.h"

using namespace ::testing;

class RotateTest : public Test{
  protected:
   Object *obj;
   RotatableAdapterMock *rotate_adapter;

   virtual void SetUp() override { 
    obj = new Object();
    rotate_adapter = new RotatableAdapterMock(obj);
   }
   virtual void TearDown() override { 
    delete rotate_adapter;
    delete obj;
   }
};

TEST_F(RotateTest, rotate) {
   EXPECT_CALL(*rotate_adapter, getDirection()).WillOnce(Return(1));
   EXPECT_CALL(*rotate_adapter, getAngularVelocity()).WillOnce(Return(2));
   EXPECT_CALL(*rotate_adapter, getDirectionsNumber()).WillOnce(Return(8));

   Rotate cmd(rotate_adapter);
   cmd.Execute();

   EXPECT_EQ(3, obj->getProperty("Direction"));
}