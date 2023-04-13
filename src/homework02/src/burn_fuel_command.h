#pragma once

#include "object.h"
#include "icommand.h"

class BurnFuelCommand : public ICommand {
    public:
     explicit BurnFuelCommand(Object *obj);
     virtual void execute() override;
    private:
     Object *obj_;
};