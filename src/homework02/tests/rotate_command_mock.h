#pragma once
#include <gmock/gmock.h>
#include "rotate_command.h"

class RotateCommandMock : public RotateCommand {
 public:
  MOCK_METHOD(void, execute, (), (override));
};