#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "test_enviriment.h"
#include "create_game_request.h"

UsersGame Environment::users_game;
uint64_t Environment::id_game;
std::string Environment::jwt;

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::AddGlobalTestEnvironment(new Environment());
  return RUN_ALL_TESTS();
}