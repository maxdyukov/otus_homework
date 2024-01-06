#pragma once

#include <mutex>
#include <queue>
#include <condition_variable>

#include "icommand.h"

#include "state.h"

class CommandExecutor {
 public:
  explicit CommandExecutor();
  void executeCommand();
  void addCommand(ICommand* cmd);

 public:
  uint32_t countCommandInQueue() const;

 private:

  void changeState(std::unique_ptr<State> state);
  
  std::mutex mtx_;
  std::condition_variable conditionVariable;

  friend class State;
  std::queue<ICommand*> queue_cmd_;
  std::unique_ptr<State> state_;
};