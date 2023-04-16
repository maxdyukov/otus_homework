#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "object_mock.h"
#include "change_velocity_command.h"

using namespace ::testing;

class ChangeVelocityCommandTest : public Test {
    protected:
     ObjectMock *obj;
     ChangeVelocityCommand *command;
     int value_change{-1};

     void SetUp() override { 
        obj = new ObjectMock();
        command = new ChangeVelocityCommand(obj, value_change);
     }
     void TearDown() override {
        delete command;
        delete obj;
     }
};

TEST_F(ChangeVelocityCommandTest, change_velocity){
     EXPECT_CALL(*obj, getProperty("Velocity")).WillOnce(Return(10));
     EXPECT_CALL(*obj, setProperty("Velocity", 9)).Times(1);

     ASSERT_NO_THROW(command->execute());
}