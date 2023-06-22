#pragma once

#include "command_executor.h"

#include "icommand.h"

class CommandSoftStop : public ICommand {
 public:
  CommandSoftStop(CommandExecutor *cmd_exec) : cmd_exec_(cmd_exec) {}
  virtual void execute() override { cmd_exec_->setSoftStop(); }
  private:
  CommandExecutor *cmd_exec_;
};