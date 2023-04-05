#include "object.h"

Object::Object() {}

Object::Object(Object &a_object) { property_ = a_object.property_; }

int Object::getProperty(const std::string &property){
  auto it = property_.find(property);
  if(it == property_.end()){
    throw std::invalid_argument("Property '" + property + "' not found");
  }
  return it->second;
}

void Object::setPosition(std::vector<int> &position){
  if (position.size() > 2){
    throw std::runtime_error("Failed set position");
  }
  property_["PositionX"] = position[0];
  property_["PositionY"] = position[1];
}

std::vector<int> Object::getPosition(){
  auto itX = property_.find("PositionX");
  auto itY = property_.find("PositionY");
  if (itX == property_.end() || itY == property_.end()){
    throw std::invalid_argument("Not found position");
  }
  return {itX->second, itY->second};
}