#pragma once

#include "icommand.h"
#include "object.h"

class MoveCommand : public ICommand {
 public:
  explicit MoveCommand(Object *obj, int speed) : obj_(obj), speed_(speed) {}
  virtual void execute() {}

 private:
  Object *obj_;
  int speed_;
};
