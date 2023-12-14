#pragma once

#include "request.h"
#include "type_def.h"

class CreateTokenRequest : public Request {
 public:
  explicit CreateTokenRequest(UsersGame *a_users_game);
  virtual void process(const std::string& json_req);
  std::string get_jwt_token();

  private:
   UsersGame *users_game;
   std::string jwt_token{};
};