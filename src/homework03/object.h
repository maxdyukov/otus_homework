#pragma once

#include <string>
#include <vector>
#include <map>

class Object{
  public:
   Object();
   Object(Object &);
   virtual int getProperty(const std::string &property);
   virtual void setPosition(std::vector<int> &position);
   virtual std::vector<int> getPosition();
  private:
   std::map<std::string, int> property_;
};
