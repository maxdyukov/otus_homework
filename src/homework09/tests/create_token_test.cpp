#include <gtest/gtest.h>
#include <jwt-cpp/jwt.h>

#include "create_token_request.h"
#include "test_enviriment.h"
#include <sstream>

TEST(create_token_test, positive) {
  Request *req = new CreateTokenRequest(&Environment::users_game);

  std::string json{"{\"user\":\"user1\", \"id_game\": " +
                   std::to_string(Environment::id_game) + "}"};
  req->process(json);
  auto jwt = static_cast<CreateTokenRequest *>(req)->get_jwt_token();

  EXPECT_FALSE(jwt.empty());
  EXPECT_NE(0, jwt.size());

  Environment::jwt = jwt;

  delete req;
}