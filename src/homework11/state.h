#pragma once

#include <iostream>
#include <memory>

#include "icommand.h"
class CommandExecutor;

class State {
 public:
  State(CommandExecutor *commamd_executor)
      : command_executor_(commamd_executor) {}
  virtual std::unique_ptr<State> handle() = 0;
  virtual ~State() {}
protected:
 ICommand *getCommand();
 void removeCommand();

protected:
 CommandExecutor *command_executor_;
};