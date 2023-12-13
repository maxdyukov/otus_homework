#pragma once

#include <map>
#include <string>

using UsersGame = std::map<std::string, uint64_t>;

struct DataForCreateToken {
  std::string user;
  uint64_t id_game;
};
