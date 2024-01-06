#include "default_state.h"

#include "move_to_state.h"

DefaultState::DefaultState(CommandExecutor *commamd_executor)
    : State(commamd_executor) {;
}

std::unique_ptr<State> DefaultState::handle() {
  ICommand *command = getCommand();
  if (command->type() == ICommand::Type::HardStop) {
    return nullptr;
  } else if (command->type() == ICommand::Type::MoveToCommand) {
    return std::make_unique<MoveToState>(command_executor_);
  } else {
    command->execute();
    this->removeCommand();
    return std::make_unique<DefaultState>(command_executor_);
  }
}