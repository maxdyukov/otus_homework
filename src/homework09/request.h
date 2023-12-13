#pragma once

#include <string>

class Request {
 public:
  Request() = default;
  virtual ~Request() = default;
  virtual void process(const std::string &json_request) = 0;
};