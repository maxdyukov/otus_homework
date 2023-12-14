#pragma once

#include <string>
#include "type_def.h"

class Request {
 public:
  explicit Request(UsersGame *a_users_game) : users_game(a_users_game){}
  virtual ~Request() = default;
  virtual void process(const std::string &json_request) = 0;
  protected:
   UsersGame *users_game;
};