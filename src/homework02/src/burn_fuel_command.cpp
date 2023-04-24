#include "burn_fuel_command.h"

BurnFuelCommand::BurnFuelCommand(Object *obj) : obj_(obj){}

void BurnFuelCommand::execute() {
  int fuel_usage = obj_->getProperty("FuelUsage");
  int fuel = obj_->getProperty("Fuel");
  obj_->setProperty("Fuel", fuel - fuel_usage);
}
