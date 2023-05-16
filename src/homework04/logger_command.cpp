#include "logger_command.h"

LoggerCommand::LoggerCommand(ICommand* cmd, std::string ex_str)
    : cmd_(cmd), str_string_(ex_str) {}

void LoggerCommand::execute() {
  std::cerr << typeid(*cmd_).name() << " has error. " << str_string_.c_str()
            << std::endl;
}