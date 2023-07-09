#pragma once
#include <gmock/gmock.h>
#include "move_command.h"

class MoveCommandMock : public MoveCommand {
 public:
  MoveCommandMock(Object *obj, int speed) : MoveCommand(obj, speed) {}
  MOCK_METHOD(void, execute, (), (override));
};