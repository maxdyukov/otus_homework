#include "create_game_request.h"

#include <boost/json.hpp>
#include <boost/json/value.hpp>
#include <iostream>

CreateGameRequest::CreateGameRequest(UsersGame *a_users_game)
    : Request(a_users_game) {}

void CreateGameRequest::process(const std::string &json_request) {
  try {
    boost::json::value jv = boost::json::parse(json_request);

    uint64_t id_game = ::rand();

    boost::json::value arr = jv.at("users");

    for (auto it = arr.as_array().begin(); it != arr.as_array().end(); it++) {
      if (this->users_game->count(it->as_string().c_str())) {
        std::cerr << "User " << it->as_string() << " is playing now";
        continue;
      } else {
        std::string player{it->as_string().c_str()};
        this->users_game->operator[](player) = id_game;
      }
    }

    id_last_game_ = id_game;
  } catch (...) {
    std::cerr << "Error parsing incoming json";
    id_last_game_ = 0;
    return;
  }
}

uint64_t CreateGameRequest::get_id_game() { return id_last_game_; }