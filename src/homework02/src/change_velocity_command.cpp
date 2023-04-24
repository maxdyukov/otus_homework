#include "change_velocity_command.h"

ChangeVelocityCommand::ChangeVelocityCommand(Object *obj, int value_change) 
    : obj_(obj), value_change_(value_change) {}

void ChangeVelocityCommand::execute(){
  int current_velosity = obj_->getProperty("Velocity");
  obj_->setProperty("Velocity", current_velosity + value_change_);
}