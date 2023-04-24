#include "rotable_adapter.h"

RotatableAdapter::RotatableAdapter(Object *object) : object_(object){}

void RotatableAdapter::setDirectory(int directory){
  object_->setProperty("Direction", directory);
}
int RotatableAdapter::getDirection(){
  return object_->getProperty("Directory");
}
int RotatableAdapter::getAngularVelocity(){
  return object_->getProperty("AngularVelocity");

}
int RotatableAdapter::getDirectionsNumber(){
  return object_->getProperty("DirectionsNumber");
}