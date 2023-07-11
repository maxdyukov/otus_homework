#include "command_executor.h"
#include <iostream>


CommandExecutor::CommandExecutor() {}

void CommandExecutor::executeCommand() {
  while (isRunning_) {
    std::unique_lock<std::mutex> lck(mtx_);

    if(isSoftStop && queue_cmd_.empty()){
      isRunning_ = false;
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
      std::cerr << ex.what() << std::endl;
    }
  }
}

void CommandExecutor::addCommand(ICommand* cmd) {
  std::lock_guard<std::mutex> lck(mtx_);
  queue_cmd_.push(cmd);
}

bool CommandExecutor::isRunning() { return isRunning_; }

void CommandExecutor::setSoftStop() { isSoftStop = true; }

void CommandExecutor::setHardStop() { isRunning_ = false; }

uint32_t CommandExecutor::countCommandInQueue() const { return queue_cmd_.size(); }