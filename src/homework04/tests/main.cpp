#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "check_fuel_command.h"
#include "exception_handler.h"
#include "logger_command.h"
#include "object_mock.h"
#include "queue_command.h"
#include "repeate_command.h"

using namespace ::testing;

TEST(LoggerCommandTest, output_cerr) {
  ObjectMock obj;
  CheckFuelCommand check_fuel_command(&obj);
  LoggerCommand log(&check_fuel_command, "Log it");

  testing::internal::CaptureStderr();
  log.execute();
  std::string log_str = testing::internal::GetCapturedStderr();
  EXPECT_STREQ("16CheckFuelCommand has error. Log it\n", log_str.c_str());
}

TEST(LoggerCommandTest, logger_hadler) {
  std::queue<ICommand*> queue;
  QueueCommand queue_cmd(queue);

  queue_cmd.addCommand(new LoggerCommand(&queue_cmd, "Queue exception"));
  ExceptionHandlerLog handler(
      &queue_cmd, new LoggerCommand(&queue_cmd, "Queue exception 2"),
      new LogException("Lot it"));

  testing::internal::CaptureStderr();
  handler.handle();
  queue_cmd.execute();
  std::string log_str = testing::internal::GetCapturedStderr();
  EXPECT_STREQ(
      "12QueueCommand has error. Queue exception\n13LoggerCommand has error. "
      "Lot it\n",
      log_str.c_str());
}

TEST(CommandExceptionTest, command_exception_handler) {
  std::queue<ICommand*> queue;
  ObjectMock obj;
  CheckFuelCommand check_fuel_command(&obj);

  queue.push(new CheckFuelCommand(&obj));

  QueueCommand queue_cmd(queue);
  EXPECT_CALL(obj, getProperty("Fuel"))
      .Times(2)
      .WillRepeatedly(::testing::Return(0));

  testing::internal::CaptureStderr();
  queue_cmd.execute();
  std::string log_str = testing::internal::GetCapturedStderr();
  EXPECT_STREQ("14RepeateCommand has error. No fuel\n", log_str.c_str());
}

TEST(RepeateCommandTest, test_command) {
  ObjectMock obj;
  CheckFuelCommand check_fuel_command(&obj);

  EXPECT_CALL(obj, getProperty("Fuel"))
      .Times(2)
      .WillRepeatedly(::testing::Return(0));

  RepeateCommand repeate_command(&check_fuel_command, 2);
  testing::internal::CaptureStderr();
  EXPECT_NO_THROW(repeate_command.execute());
  std::string log_str = testing::internal::GetCapturedStderr();
  EXPECT_STREQ("14RepeateCommand has error. No fuel\n", log_str.c_str());
}

TEST(RepeateCommandTest, repeate_handler) {
  std::queue<ICommand*> queue;
  ObjectMock obj;
  QueueCommand queue_cmd(queue);

  EXPECT_CALL(obj, getProperty("Fuel"))
      .Times(1)
      .WillRepeatedly(::testing::Return(2));

  ExceptionHandlerRepeate handler(&queue_cmd, new CheckFuelCommand(&obj),
                                 new CommandException("Command exception"));
  handler.handle();

  ASSERT_NO_THROW(queue_cmd.execute());
}

TEST(ExceptionHandlerRepeateAndLogTest, test){
      std::queue<ICommand*> queue;
  ObjectMock obj;
  QueueCommand queue_cmd(queue);

  EXPECT_CALL(obj, getProperty("Fuel"))
      .Times(1)
      .WillRepeatedly(::testing::Return(0));

  ExceptionHandlerRepeate handler(&queue_cmd, new CheckFuelCommand(&obj),
                                 new CommandException("Command exception"));
  handler.handle();

  testing::internal::CaptureStderr();
  ASSERT_NO_THROW(queue_cmd.execute());
  std::string log_str = testing::internal::GetCapturedStderr();
  EXPECT_STREQ("14RepeateCommand has error. No fuel\n", log_str.c_str());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}