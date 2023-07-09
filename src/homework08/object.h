#pragma once

#include <string>

class Object {
    public: 
      Object(int id) : id_(id){}
      virtual ~Object() = default;
      virtual int getProperty(const char* name_property) = 0;
      virtual void setProperty(const char* name_property, int value) = 0;
    private:
     int id_;
};
