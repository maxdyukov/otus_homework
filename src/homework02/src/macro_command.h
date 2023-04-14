#pragma once

#include "icommand.h"
#include <vector>

class MacroCommand : public ICommand{
    public:
     MacroCommand(std::vector<ICommand*> commands);
     ~MacroCommand() {}
     virtual void execute() override;

    private:
     std::vector<ICommand*> commands_;
};