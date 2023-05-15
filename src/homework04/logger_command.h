#pragma once

#include <iostream>

#include "icommand.h"

class LoggerCommand : public ICommand {
 public:
  LoggerCommand(ICommand* cmd, std::string ex_str);
  ~LoggerCommand() = default;
  void execute();

 private:
  ICommand* cmd_;
  std::string str_string_;
};