#include <gtest/gtest.h>
#include "check_user_request.h"
#include "test_enviriment.h"

TEST(check_user_test, positive){
  Request *req = new CheckUserRequest(&Environment::users_game);

  std::string json{"{\"user\":\"user1\", \"token\": \"" + Environment::jwt + "\"}"};
  ASSERT_NO_THROW(req->process(json));

  ASSERT_TRUE(static_cast<CheckUserRequest *>(req)->check());
}