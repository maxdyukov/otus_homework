#pragma once

#include <string>
#include <vector>
#include <map>

class Object{
  public:
   Object();
   Object(Object &);
   virtual int getProperty(const std::string &property);
   virtual void setProperty(const std::string &property, int value);
  private:
   std::map<std::string, int> property_;
};
