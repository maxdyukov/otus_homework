#include "rotate.h"

Rotate::Rotate(RotatableAdapter *adapter) : adapter_(adapter){}

void Rotate::Execute(){
  adapter_->setDirectory(
      (adapter_->getDirection() + adapter_->getAngularVelocity()) %
      adapter_->getDirectionsNumber());
}