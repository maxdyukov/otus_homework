#pragma once

#include "object.h"

class ICommand {
 public:
  virtual void execute() = 0;
};

class CommandException  {
 public:
  explicit CommandException(const char *msg) : msg_(msg) {}
  virtual const char* what() const { return msg_.c_str(); }
 private:
  std::string msg_;
};