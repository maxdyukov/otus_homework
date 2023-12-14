#pragma once

#include "request.h"

class CreateTokenRequest : public Request {
 public:
  explicit CreateTokenRequest(UsersGame *a_users_game);
  virtual void process(const std::string& json_req) override;
  std::string get_jwt_token();

  private:
   std::string jwt_token{};
};