#pragma once

#include "icommand.h"
#include "object.h"

class MoveCommand : public ICommand {
    public:
     explicit MoveCommand(Object *obj) : obj_(obj){}
     virtual void execute() = 0;
    private:
     Object *obj_;
};
