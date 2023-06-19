#pragma once

#include "icommand.h"
#include <thread>
#include "command_executor.h"

class CommandThreadRun : public ICommand {
 public:
  explicit CommandThreadRun(CommandExecutor *cmd_exec);
  ~CommandThreadRun();
  virtual void execute() override;

 private:
  CommandExecutor *cmd_exec_;
  std::thread thread_;
};