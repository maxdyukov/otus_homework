#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "object_mock.h"
#include "check_fuel_command.h"
#include "burn_fuel_command.h"
#include "move_command_mock.h"
#include "macro_command.h"

using namespace ::testing;

class MacroCommandTest : public Test {
    protected:
     ObjectMock *obj;
     CheckFuelCommand *check_fuel_command;
     BurnFuelCommand *burn_fuel_command;
     MoveCommandMock *move_command;

     void SetUp() override { 
        obj = new ObjectMock();
        check_fuel_command = new CheckFuelCommand(obj);
        burn_fuel_command = new BurnFuelCommand(obj);
        move_command = new MoveCommandMock(obj);
     }
     void TearDown() override { 
        delete move_command;
        delete burn_fuel_command;
        delete check_fuel_command;
        delete obj;
     }
};

TEST_F(MacroCommandTest, execute_no_throw){
     EXPECT_CALL(*obj, getProperty("Fuel")).WillRepeatedly(Return(10));
     EXPECT_CALL(*move_command, execute()).Times(1);
     EXPECT_CALL(*obj, getProperty("FuelUsage")).WillOnce(Return(1));
     EXPECT_CALL(*obj, setProperty("Fuel", 9)).Times(1);

     std::vector<ICommand*> v_commands = {check_fuel_command, move_command,
                                           burn_fuel_command};

     MacroCommand macro_command(v_commands);
     ASSERT_NO_THROW(macro_command.execute());
}

TEST_F(MacroCommandTest, execute_throw){
     EXPECT_CALL(*obj, getProperty("Fuel")).WillRepeatedly(Return(0));

     std::vector<ICommand*> v_commands = {check_fuel_command, move_command,
                                           burn_fuel_command};

     MacroCommand macro_command(v_commands);
     ASSERT_THROW(macro_command.execute(), CommandException);
}