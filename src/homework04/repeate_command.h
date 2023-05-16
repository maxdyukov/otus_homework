#pragma once

#include "icommand.h"
#include "logger_command.h"

class RepeateCommand : public ICommand {
 public:
  explicit RepeateCommand(ICommand *cmd, int count_repeate = 1)
      : cmd_(cmd), count_repeate_(count_repeate) {}
  virtual void execute() { 
    try{
      cmd_->execute();
    } catch(std::exception &ex) {
      current_repeate++;
      if(current_repeate <= count_repeate_){
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
  int current_repeate{1};
};