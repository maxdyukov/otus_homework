#pragma once

#include "icommand.h"
#include "logger_command.h"

class RepeateCommand : public ICommand {
 public:
  explicit RepeateCommand(ICommand *cmd, int count_repeate = 1)
      : cmd_(cmd) {}
  virtual void execute() { 
    try{
      cmd_->execute();
    } catch(std::exception &ex) {
      count_repeate_++;
      if(count_repeate_ <= 2){
        this->execute();
      } else {
        LoggerCommand logger(this, ex.what());
        logger.execute();
      }
    }
  }
  ~RepeateCommand() = default;

 private:
  ICommand *cmd_;
  int count_repeate_;
};