#pragma once

#include <any>
#include <map>
#include <string>

#include "object.h"

class Contex {
 public:
  Contex() {}
  ~Contex() {}
  std::any get(const std::string& property) { return contex_[property]; }
  Contex& set(const std::string& property, std::any value) {
    contex_[property] = value;
      return *this;
  }

 private:
  std::map<std::string, std::any> contex_;
};
