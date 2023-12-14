#include "create_token_request.h"

#include <jwt-cpp/jwt.h>

#include <boost/json.hpp>
#include <boost/json/value.hpp>

CreateTokenRequest::CreateTokenRequest(UsersGame* a_users_game)
    : Request(a_users_game) {}

void CreateTokenRequest::process(const std::string& json_request) {
  try {
    boost::json::value jv = boost::json::parse(json_request);

    std::string user{jv.at("user").as_string().c_str()};
    uint64_t id_game(jv.at("id_game").as_int64());

    if (users_game->count(user)) {
      jwt_token =
          jwt::create()
              .set_issuer("auth0")
              .set_type("JWS")
              .set_payload_claim("id_game", jwt::claim(std::to_string(id_game)))
              .sign(jwt::algorithm::hs256{"secret"});
    }
  } catch (std::invalid_argument &ex) {
    std::cerr << ex.what() << std::endl;
    jwt_token.clear();
    return;
  }
}

std::string CreateTokenRequest::get_jwt_token() { return jwt_token; }