#pragma once 

#include <gtest/gtest.h>
#include "create_game_request.h"

class Environment : public ::testing::Environment {
 public:
  static UsersGame users_game;
  static uint64_t id_game;
  static std::string jwt;
  ~Environment() override {}
};