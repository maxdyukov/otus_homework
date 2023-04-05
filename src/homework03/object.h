#pragma once

#include <string>
#include <vector>
#include <map>

class Object{
  public:
    Object() = default;
    Object(Object &) = default;
    virtual int getProperty(const std::string &property) = 0;
    virtual void setPosition(std::vector<int> &position) = 0;
    virtual std::vector<int> getPosition() = 0;
};
