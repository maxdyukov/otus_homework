#include "command_executor.h"

#include "exception_handler.h"

CommandExecutor::CommandExecutor(std::queue<ICommand*>& queue)
    : queue_cmd_(queue) {}

void CommandExecutor::executeCommand() {
  while (isRunning) {
    std::unique_lock<std::mutex> lck(mtx_);

    if(isSoftStop && queue_cmd_.empty()){
      return;
    }

    while (queue_cmd_.empty()) {
      conditionVariable.wait(lck);
    }
    ICommand* cmd = queue_cmd_.front();
    queue_cmd_.pop();
    lck.unlock();

    try {
      cmd->execute();
    } catch (std::exception& ex) {
      auto handler = ExceptionHandle::handle(this, &ex);
      handler->handle();
    }
  }
}

void CommandExecutor::addCommand(ICommand* cmd) {
  std::lock_guard<std::mutex> lck(mtx_);
  queue_cmd_.push(cmd);
}

void CommandExecutor::setSoftStop() { isSoftStop = true; }

void CommandExecutor::setHardStop() { isRunning = false; }