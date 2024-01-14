#include "command_executor.h"

#include <iostream>

#include "default_state.h"
#include "move_to_state.h"

CommandExecutor::CommandExecutor() { state_.reset(new DefaultState(this)); }

void CommandExecutor::changeState(std::unique_ptr<State> state) {
  state_ = std::move(state);
}

void CommandExecutor::executeCommand() {
  while (state_) {
    std::unique_lock<std::mutex> lck(mtx_);

    while (queue_cmd_.empty()) {
      conditionVariable.wait(lck, [&]() { return this->queue_cmd_.empty(); });
    }

    try {
      state_ = state_->handle();
    } catch (std::exception& ex) {
      std::cerr << ex.what() << std::endl;
    }
    lck.unlock();
  }
}

void CommandExecutor::addCommand(ICommand* cmd) {
  std::lock_guard<std::mutex> lck(mtx_);
  queue_cmd_.push(cmd);
  conditionVariable.notify_one();
}

uint32_t CommandExecutor::countCommandInQueue() const {
  return queue_cmd_.size();
}