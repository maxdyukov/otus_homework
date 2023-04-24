#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "check_fuel_command.h"
#include "object_mock.h"

using namespace ::testing;

class CheckFuelCommandTest : public Test {
    protected:
     ObjectMock *obj;

      void SetUp() override { obj = new ObjectMock(); }
      void TearDown() override { delete obj; }
};

TEST_F(CheckFuelCommandTest, execute_no_throw){
     EXPECT_CALL(*obj, getProperty("Fuel")).WillOnce(Return(20));

     CheckFuelCommand check_fuel_command(obj);
     ASSERT_NO_THROW(check_fuel_command.execute());
}

TEST_F(CheckFuelCommandTest, execute_throw){
    EXPECT_CALL(*obj, getProperty("Fuel")).WillOnce(Return(-1));

     CheckFuelCommand check_fuel_command(obj);
     ASSERT_THROW(check_fuel_command.execute(), CommandException); 
}