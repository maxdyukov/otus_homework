#pragma once
#include <gmock/gmock.h>

#include "rotate_command.h"

class RotateCommandMock : public RotateCommand {
 public:
  RotateCommandMock(Object *obj, int speed, int angle_rotate)
      : RotateCommand(obj, speed, angle_rotate) {}
  MOCK_METHOD(void, execute, (), (override));
};