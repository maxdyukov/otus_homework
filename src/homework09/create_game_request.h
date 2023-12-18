#pragma once

#include "request.h"

class CreateGameRequest : public Request {
 public:
  explicit CreateGameRequest(UsersGame *a_user_game);
  virtual void process(const std::string &json_request) override;
  uint64_t get_id_game();

 private:
  uint64_t id_last_game_{0};
};