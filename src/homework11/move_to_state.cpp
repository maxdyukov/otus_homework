#include "move_to_state.h"

#include "default_state.h"

MoveToState::MoveToState(CommandExecutor *commamd_executor)
    : State(commamd_executor) {}

std::unique_ptr<State> MoveToState::handle() {
  ICommand *command = getCommand();
  if (command->type() == ICommand::Type::HardStop) {
    return nullptr;
  } else if (command->type() == ICommand::Type::RunCommand) {
    return std::make_unique<DefaultState>(command_executor_);
  } else {
    std::cout << "Send to another queue" << std::endl;
    this->removeCommand();
    return nullptr;
  }
}