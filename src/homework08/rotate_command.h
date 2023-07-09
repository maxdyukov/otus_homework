#pragma once

#include "icommand.h"
#include "object.h"

class RotateCommand : public ICommand {
 public:
  explicit RotateCommand(Object *obj, int speed, int angle_rotate)
      : obj_(obj), speed_(speed), angle_rotate_(angle_rotate) {}
  virtual void execute() {}

 private:
  Object *obj_;
  int speed_;
  int angle_rotate_;
};