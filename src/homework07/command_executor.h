#pragma once

#include <mutex>
#include <queue>
#include <condition_variable>

#include "icommand.h"

class CommandExecutor {
 public:
  explicit CommandExecutor();
  void executeCommand();
  void addCommand(ICommand* cmd);
public:
  void setSoftStop();
  void setHardStop();
  uint32_t countCommandInQueue() const;
  bool isRunning();

 private:
  std::mutex mtx_;
  std::condition_variable conditionVariable;
  std::queue<ICommand*> queue_cmd_;
  bool isRunning_{true};
  bool isSoftStop{false};
};