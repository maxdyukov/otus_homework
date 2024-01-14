#include "state.h"
#include "command_executor.h"

ICommand* State::getCommand() { return command_executor_->queue_cmd_.front(); }

void State::removeCommand() { command_executor_->queue_cmd_.pop(); }