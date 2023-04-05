#include "move.h"

Move::Move(MovableAdapter *m_adapte) : adapter_(m_adapte){}

void Move::Execute(){
  auto current_position = adapter_->getPosition();
  auto velocity = adapter_->getVelocity();
  for (int i = 0; i < current_position.size(); i++){
    current_position[i] += velocity[i];
  }
  adapter_->setPosition(current_position);
}