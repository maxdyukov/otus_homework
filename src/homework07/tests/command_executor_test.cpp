#include "command_executor.h"

#include <gtest/gtest.h>

#include <thread>
#include <chrono>

#include "command_soft_stop.h"
#include "command_thread_run.h"
#include "commans_hard_stop.h"

class CommandExecutorTest : public ::testing::Test {
 protected:
  CommandExecutor *cmd_exec_;
  CommandThreadRun *thread_run_;
  void SetUp() override {
    cmd_exec_ = new CommandExecutor();
    thread_run_ = new CommandThreadRun(cmd_exec_);
  }
  void TearDown() override { 
    delete thread_run_;
    delete cmd_exec_;
  }
};

TEST_F(CommandExecutorTest, start_thread) {
    thread_run_->execute();
    //поток успесшно стартует и завершается
    ASSERT_TRUE(true); 
}

TEST_F(CommandExecutorTest, soft_stop){
    cmd_exec_->addCommand(new CommandSoftStop(cmd_exec_));
    cmd_exec_->addCommand(new CommandSoftStop(cmd_exec_));
    cmd_exec_->addCommand(new CommandSoftStop(cmd_exec_));

    thread_run_->execute();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    EXPECT_EQ(0, cmd_exec_->countCommandInQueue());
    ASSERT_FALSE(cmd_exec_->isRunning());
}

TEST_F(CommandExecutorTest, hard_stop){
    cmd_exec_->addCommand(new CommandSoftStop(cmd_exec_));
    cmd_exec_->addCommand(new CommandSoftStop(cmd_exec_));
    cmd_exec_->addCommand(new CommandHardStop(cmd_exec_));
    cmd_exec_->addCommand(new CommandSoftStop(cmd_exec_));
    cmd_exec_->addCommand(new CommandSoftStop(cmd_exec_));

    thread_run_->execute();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    EXPECT_NE(0, cmd_exec_->countCommandInQueue());
    EXPECT_EQ(2, cmd_exec_->countCommandInQueue());
    ASSERT_FALSE(cmd_exec_->isRunning());
}
