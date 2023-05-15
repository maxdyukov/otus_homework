#pragma once

#include <map>
#include <stdexcept>
#include <string>
#include <typeinfo>

#include "icommand.h"
#include "queue_command.h"

class ExceptionHandler {
 public:
  ExceptionHandler(QueueCommand* queue_cmd, ICommand* cmd, std::exception* ex);
  virtual void handle() = 0;

 protected:
  QueueCommand* queue_cmd_;
  ICommand* cmd_;
  std::exception* ex_;
};

class ExceptionHandlerLog : public ExceptionHandler {
 public:
  ExceptionHandlerLog(QueueCommand* queue_cmd, ICommand* cmd,
                      std::exception* ex);
  virtual void handle() override;
};

class ExceptionHandlerRepeate : public ExceptionHandler {
 public:
  ExceptionHandlerRepeate(QueueCommand* queue_cmd, ICommand* cmd,
                          std::exception* ex);
  virtual void handle() override;
};

class ExceptionHandlerRepeateAndLog : public ExceptionHandler {
 public:
  ExceptionHandlerRepeateAndLog(QueueCommand* queue_cmd, ICommand* cmd,
                                std::exception* ex);
  virtual void handle() override;

 private:
  bool is_first{false};
};

class ExceptionHandle {
 public:
  static ExceptionHandler* hanler(QueueCommand* queue_cmd, ICommand* cmd,
                                  std::exception* ex) {
    if (typeid(*ex) == typeid(CommandException)){
      return new ExceptionHandlerRepeate(queue_cmd, cmd, ex);
    } else if (typeid(*ex) == typeid(LogException)){
      return new ExceptionHandlerLog(queue_cmd, cmd, ex);
    } else {
      return new ExceptionHandlerRepeateAndLog(queue_cmd, cmd, ex);
    }
  }
};