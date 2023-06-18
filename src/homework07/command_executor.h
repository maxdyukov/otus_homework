#pragma once

#include <mutex>
#include <queue>

#include "icommand.h"

class CommandExecutor {
 public:
  CommandExecutor(std::queue<ICommand*>& queue);
  void executeCommand();
  void addCommand(ICommand* cmd);
public:
  void setSoftStop();
  void setHardStop();

 private:
  std::mutex mtx_;
  std::condition_variable conditionVariable;
  std::queue<ICommand*> queue_cmd_;
  bool isRunning{true};
  bool isSoftStop{false};
};