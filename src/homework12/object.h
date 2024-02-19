#pragma once

#include <string>

class Object {
    public:
     virtual int getProperty(const char* name_property) = 0;
     virtual void setProperty(const char* name_property, int value) = 0;
};
