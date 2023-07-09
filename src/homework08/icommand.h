#pragma once

#include <string>
#include <stdexcept>

class ICommand {
 public:
  virtual void execute() = 0;
  virtual ~ICommand() = default;
};

class CommandException : public std::exception  {
 public:
  explicit CommandException(const char *msg) : msg_(msg) {}
  ~CommandException() = default;
  virtual const char* what() const noexcept { return msg_.c_str(); }

 private:
  std::string msg_;
};

class LogException : public std::exception  {
 public:
  explicit LogException(const char *msg) : msg_(msg) {}
  ~LogException() = default;
  virtual const char* what() const noexcept { return msg_.c_str(); }

 private:
  std::string msg_;
};