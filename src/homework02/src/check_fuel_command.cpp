#include "check_fuel_command.h"

CheckFuelCommand::CheckFuelCommand(Object *obj) : obj_(obj) {}

void CheckFuelCommand::execute() { 
    int fuel = obj_->getProperty("Fuel"); 
    if (fuel <= 0){
      throw CommandException("No fuel");
    }
}