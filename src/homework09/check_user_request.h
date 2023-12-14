#pragma once

#include <jwt-cpp/jwt.h>
#include "request.h"
#include "type_def.h"

class CheckUserRequest : public Request {
    public:
     explicit CheckUserRequest(UsersGame *a_users_game);
     virtual void process(const std::string& json_request) override;
     bool check();
    private:
     bool is_valid{false};
};