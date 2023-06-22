#include "command_thread_run.h"

#include "command_executor.h"

CommandThreadRun::CommandThreadRun(CommandExecutor *cmd_exec)
    : cmd_exec_(cmd_exec), thread_{} {}

void CommandThreadRun::execute(){
  thread_ = std::thread{&CommandExecutor::executeCommand, cmd_exec_};
}

CommandThreadRun::~CommandThreadRun() {
  cmd_exec_->setHardStop();
  if (thread_.joinable()){
    thread_.join();
  }
}