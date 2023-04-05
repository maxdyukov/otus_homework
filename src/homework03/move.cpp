#include "move.h"

Move::Move(MovableAdapter m_adapte) : adapter_(m_adapte){}

void Move::Execute(){
  std::vector<int> position{};
  for (size_t i = 0; i < adapter_.getPosition().size(); i++) {
    position[i] = adapter_.getPosition()[i] + adapter_.getVelocity()[i];
  }
  adapter_.setPosition(position);
}