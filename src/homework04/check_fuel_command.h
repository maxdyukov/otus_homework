#pragma once

#include "object.h"
#include "icommand.h"

class CheckFuelCommand : public ICommand {
    public:
     explicit CheckFuelCommand(Object *obj);
     ~CheckFuelCommand() = default;
     virtual void execute() override;

    private:
     Object *obj_;
};