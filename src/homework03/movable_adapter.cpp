#include "movable_adapter.h"

#include <math.h>

MovableAdapter::MovableAdapter(Object *obj) : obj_(obj){}

std::vector<int> MovableAdapter::getPosition() { return obj_->getPosition(); }

void MovableAdapter::setPosition(std::vector<int> pos){
  obj_->setPosition(pos);
}

std::vector<int> MovableAdapter::getVelocity() { 
    int d = obj_->getProperty("Direction");
    int n = obj_->getProperty("DirectionNumber");
    int v = obj_->getProperty("Velocity");

    return {static_cast<int>(v * std::cos(d / 360 * n)), static_cast<int>(v * std::sin(d / 360 * n))};
}