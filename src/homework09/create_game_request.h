#pragma once

#include "request.h"
#include "type_def.h"

class CreateGameRequest : public Request {
 public:
  explicit CreateGameRequest(UsersGame *a_user_game);
  virtual void process(const std::string &json_request) override;

 private:
  UsersGame *users_game;
};