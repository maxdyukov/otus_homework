#pragma once

#include "movable_adapter.h"

class Move{
  public:
   Move(MovableAdapter m_adapter);
   void Execute();
  private:
   MovableAdapter adapter_;
};
