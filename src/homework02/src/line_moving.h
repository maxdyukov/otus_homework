#pragma once

#include <queue>
#include "icommand.h"
#include "object.h"

class LineMoving : public ICommand{
    public:
     LineMoving(Object *obj, ICommand *command, int destPosition);
     virtual void execute() override;
    private:
     Object *obj_;
     int destination_;
     std::queue<ICommand *> commands_;
};