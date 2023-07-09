#pragma once

#include <map>

#include "command_executor.h"
#include "icommand.h"
#include "object.h"
#include "type_def.h"

using AllObjects = std::map<int, std::vector<Object *>>;

class InterpretCommand : public ICommand {
 public:
  InterpretCommand(const TMessage &a_msg, AllObjects *a_objects,
                   CommandExecutor *a_cmd_exec);
  void execute() override;

 private:
 private:
  TMessage msg_;
  AllObjects *game_objects_;
  CommandExecutor *cmd_exec_;
};