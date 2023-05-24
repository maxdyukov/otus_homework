#pragma once

#include <queue>
#include <stdexcept>

#include "icommand.h"

class QueueCommand : public ICommand {
    public:
     QueueCommand(std::queue<ICommand*>& a_commands);
     ~QueueCommand() = default;
     virtual void execute() override;
     void addCommand(ICommand* a_comm);

    private:
     std::queue<ICommand*> commands_;
};