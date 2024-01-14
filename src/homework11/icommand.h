#pragma once

#include <string>

class CommandExecutor;

class ICommand {
 public:
  enum class Type { HardStop, MoveToCommand, RunCommand };
  ICommand(Type type) : type_(type) {}

  virtual void execute() = 0;
  virtual Type type() { return type_; }

 private:
  Type type_;
};

class HardStop : public ICommand {
 public:
  HardStop() : ICommand(Type::HardStop) {}
  void execute() {}
};

class MoveToCommand : public ICommand{
  public:
    MoveToCommand() : ICommand(Type::MoveToCommand) {}
    void execute() {}
};

class NormalCommand : public ICommand {
  public:
    NormalCommand() : ICommand(Type::RunCommand){}
    void execute () {}
};

class CommandException {
 public:
  explicit CommandException(const char* msg) : msg_(msg) {}
  virtual const char* what() const { return msg_.c_str(); }

 private:
  std::string msg_;
};