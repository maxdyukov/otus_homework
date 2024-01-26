#pragma once

#include "handler.h"
#include "game_area.h"

class DefineFieldCommand : public AbstractHandler {
public:
    DefineFieldCommand(Contex *contex) : AbstractHandler(contex){}
    virtual void Handle() override {
        GameArea *game_area = std::any_cast<GameArea*>(contex_->get("game_area"));
        contex_->set("isFindObject", false);
        AbstractHandler::SetNext(game_area);
        AbstractHandler::Handle();
    }
};

