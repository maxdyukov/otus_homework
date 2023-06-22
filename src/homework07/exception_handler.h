#pragma once

#include <map>
#include <queue>
#include <stdexcept>
#include <string>
#include <typeinfo>

#include "icommand.h"

class CommandExecutor;

class ExceptionHandler {
 public:
  ExceptionHandler(CommandExecutor* cmd_exec, std::exception* ex)
      : cmd_exec_(cmd_exec), ex_(ex) {}
  virtual void handle() = 0;

 protected:
  CommandExecutor* cmd_exec_;
  std::exception* ex_;
};

class ExceptionSoftStop : public ExceptionHandler {
 public:
  ExceptionSoftStop(CommandExecutor* cmd_exec, std::exception* ex);
  virtual void handle() override;
};

class ExceptionHardStop : public ExceptionHandler {
 public:
  ExceptionHardStop(CommandExecutor* cmd_exec, std::exception* ex);
  virtual void handle() override;
};

class ExceptionHandle {
 public:
  static ExceptionHandler* handle(CommandExecutor* cmd_exec,
                                  std::exception* ex) {
    if (typeid(*ex) == typeid(std::runtime_error)) {
      return new ExceptionSoftStop(cmd_exec, ex);
    } else {
      return new ExceptionHardStop(cmd_exec, ex);
    }
  }
};