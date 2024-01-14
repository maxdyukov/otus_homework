#include <gtest/gtest.h>
#include "command_executor.h"
#include "icommand.h"
#include <string>

TEST(HardStopCommamd, stop_run) { 
    CommandExecutor command_executor;

    command_executor.addCommand(new MoveToCommand());
    command_executor.addCommand(new HardStop());
    command_executor.addCommand(new MoveToCommand());
    command_executor.addCommand(new MoveToCommand());

    // В очереди 4 команды
    ASSERT_EQ(4, command_executor.countCommandInQueue());

    command_executor.executeCommand();

    //После выполнения до остаться 2 команды
    ASSERT_EQ(3, command_executor.countCommandInQueue());
}

TEST(MoveToCommand, check){
  CommandExecutor command_executor;

  command_executor.addCommand(new MoveToCommand());

  ::testing::internal::CaptureStdout();
  command_executor.executeCommand();
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_STREQ("Send to another queue\n", output.c_str());
}