#pragma once
#include <gmock/gmock.h>
#include "move_command.h"

class MoveCommandMock : public MoveCommand {
 public:
  MOCK_METHOD(void, execute, (), (override));
};