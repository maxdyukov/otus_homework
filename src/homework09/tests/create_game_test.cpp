#include <gtest/gtest.h>
#include "create_game_request.h"
#include "test_enviriment.h"

TEST(create_game_test, positive){
    std::string json_req("{\"users\":[\"user1\",\"user2\",\"user3\"]}");

    Request *req = new CreateGameRequest(&Environment::users_game);

    EXPECT_NO_THROW(req->process(json_req));
    EXPECT_NE(0, static_cast<CreateGameRequest *>(req)->get_id_game());

    Environment::id_game = static_cast<CreateGameRequest *>(req)->get_id_game();

    delete req;
}