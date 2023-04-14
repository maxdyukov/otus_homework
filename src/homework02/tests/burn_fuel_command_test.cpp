#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "burn_fuel_command.h"
#include "object_mock.h"

using namespace ::testing;

class BurnFuelCommandTest : public Test {
    protected:
     ObjectMock *obj;

     void SetUp() override { obj = new ObjectMock(); }
     void TearDown() override{delete obj;}
};

TEST_F(BurnFuelCommandTest, execute){
     EXPECT_CALL(*obj, getProperty("FuelUsage")).WillOnce(Return(1));
     EXPECT_CALL(*obj, getProperty("Fuel")).WillOnce(Return(10));
     EXPECT_CALL(*obj, setProperty("Fuel", 9)).Times(1);

     BurnFuelCommand burn_fuel_command(obj);
     ASSERT_NO_THROW(burn_fuel_command.execute());
}