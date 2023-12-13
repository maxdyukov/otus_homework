#include "create_game_request.h"

#include <boost/json.hpp>
#include <boost/json/value.hpp>
#include <iostream>

CreateGameRequest::CreateGameRequest(UsersGame *a_users_game) {
  users_game = a_users_game;
}

void CreateGameRequest::process(const std::string &json_request) {
  boost::json::value jv = boost::json::parse(json_request);

  uint64_t id_game = ::rand();

  for (auto it = jv.as_array().begin(); it != jv.as_array().end(); it++) {
    if (this->users_game->count(it->as_string().c_str())) {
      std::cerr << "User " << it->as_string() << " is playing now";
      continue;
    } else {
      std::string player{it->as_string().c_str()};
      this->users_game->operator[](player) = id_game;
    }
  }
}