#pragma once

#include "request.h"
#include "type_def.h"

class CreateGameRequest : public Request{
    public:
        explicit CreateGameRequest(UsersGame *a_user_game);
        virtual void exec(const std::string &json_request);
    private:
        UsersGame *users_game;
};