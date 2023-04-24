#include "movable_adapter.h"

#include <math.h>
#include <stdexcept>

MovableAdapter::MovableAdapter(Object *obj) : obj_(obj){}

std::vector<int> MovableAdapter::getPosition() {
  return { obj_->getProperty("PositionX"), obj_->getProperty("PositionY")};
}

void MovableAdapter::setPosition(std::vector<int> pos) {
  if (pos.size() > 2){
    throw std::runtime_error("Failed set position");
  }
  obj_->setProperty("PositionX", pos[0]);
  obj_->setProperty("PositionY", pos[1]);

}

std::vector<int> MovableAdapter::getVelocity() {
    int d = obj_->getProperty("Direction");
    int n = obj_->getProperty("DirectionNumber");
    int v = obj_->getProperty("Velocity");

    return {static_cast<int>(v * std::cos(d / 360 * n)), static_cast<int>(v * std::sin(d / 360 * n))};
}