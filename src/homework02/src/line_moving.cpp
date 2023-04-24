#include "line_moving.h"
#include "macro_command.h"
#include "check_fuel_command.h"
#include "burn_fuel_command.h"
#include "move_command.h"

LineMoving::LineMoving(Object *obj,ICommand *command, int destPosition) : obj_(obj) {
  commands_.push(command);
}

void LineMoving::execute() {
    try{
    while(not commands_.empty()){
      auto it = commands_.front();
      it->execute();
      commands_.pop();
      int current_position = obj_->getProperty("CurrentPosition");
      if (current_position < destination_){
        commands_.push(it);
      }
    }
    }catch(CommandException &ex){
        
    }
}



