#pragma once

#include "icommand.h"
#include "object.h"

class RotateCommand : public ICommand {
 public:
  explicit RotateCommand(Object *obj);
  virtual void execute() = 0 ;
 private:
  Object *obj_;
};