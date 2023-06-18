#pragma once

#include "command_executor.h"

#include "icommand.h"

class CommandHardStop : public ICommand {
 public:
  CommandHardStop(CommandExecutor *cmd_exec) : cmd_exec_(cmd_exec) {}
  virtual void execute() override { cmd_exec_->setHardStop(); }
  private:
  CommandExecutor *cmd_exec_;
};