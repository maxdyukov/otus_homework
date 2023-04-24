#include "object.h"
#include <stdexcept>

Object::Object() {}

Object::Object(Object &a_object) { property_ = a_object.property_; }

int Object::getProperty(const std::string &property){
  auto it = property_.find(property);
  if(it == property_.end()){
    throw std::invalid_argument("Property '" + property + "' not found");
  }
  return it->second;
}

void Object::setProperty(const std::string &property, int value){
  property_[property] = value;
}