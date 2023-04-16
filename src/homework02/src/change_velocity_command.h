#pragma once

#include "icommand.h"
#include "object.h"

class ChangeVelocityCommand : public ICommand{
    public:
     ChangeVelocityCommand(Object *obj, int value_change);
     void execute();
    private:
     int value_change_;
     Object *obj_;
};