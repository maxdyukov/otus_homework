#include "check_user_request.h"

#include <boost/json.hpp>
#include <boost/json/value.hpp>

CheckUserRequest::CheckUserRequest(UsersGame* a_users_game)
    : Request(a_users_game) {}

void CheckUserRequest::process(const std::string& json_request) {
  try {
    is_valid = false;

    boost::json::value jv = boost::json::parse(json_request);

    std::string user{jv.at("user").as_string().c_str()};
    std::string token{jv.at("token").as_string().c_str()};

    auto decoded = jwt::decode(token);

    auto verifier = jwt::verify()
                        .allow_algorithm(jwt::algorithm::hs256{"secret"})
                        .with_issuer("auth0");

    verifier.verify(decoded);

    for(auto &it : decoded.get_payload_json()){
      if(it.first == "id_game"){
        auto id_game_str = it.second.to_str();
        uint64_t id_game = std::atol(id_game_str.c_str());
        if (users_game->operator[](user) == id_game){
          is_valid = true;
        }
      }
    }

  } catch (std::exception& ex) {
    std::cerr << ex.what();
    is_valid = false;
  }
}

bool CheckUserRequest::check() { return is_valid; }