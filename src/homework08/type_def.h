#pragma once

#include <boost/json.hpp>

struct TMessage{
  int id_game_;
  int id_game_obj_;
  int id_operation_;
  boost::json::array args_json_;
};