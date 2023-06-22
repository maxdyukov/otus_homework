#include "exception_handler.h"

#include "command_soft_stop.h"
#include "commans_hard_stop.h"

ExceptionSoftStop::ExceptionSoftStop(CommandExecutor* cmd_exec,
                                     std::exception* ex)
    : ExceptionHandler(cmd_exec, ex) {}

void ExceptionSoftStop::handle() {
  cmd_exec_->addCommand(new CommandSoftStop(cmd_exec_));
}

ExceptionHardStop::ExceptionHardStop(CommandExecutor* cmd_exec,
                                     std::exception* ex)
    : ExceptionHandler(cmd_exec, ex) {}

void ExceptionHardStop::handle() {
  cmd_exec_->addCommand(new CommandHardStop(cmd_exec_));
}