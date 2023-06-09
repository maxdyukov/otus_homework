#include "queue_command.h"

#include "exception_handler.h"

QueueCommand::QueueCommand(std::queue<ICommand*> &a_commands)
    : commands_(std::move(a_commands)) {}

void QueueCommand::execute() {
  while (not commands_.empty()) {
    auto comm = commands_.front();
    try {
      commands_.pop();
      comm->execute();
      delete comm;
    } catch (std::exception &ex) {
      auto handler = ExceptionHandle::hanler(this, comm, &ex);
      handler->handle();
    }
  }
}

void QueueCommand::addCommand(ICommand *a_command) {
  commands_.push(a_command);
}