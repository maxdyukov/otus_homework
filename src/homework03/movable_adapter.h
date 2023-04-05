#pragma once

#include <vector>
#include "object.h"

class MovableAdapter{
    public:
     MovableAdapter(Object *obj);

     std::vector<int> getPosition();
     void setPosition(std::vector<int> pos);
     std::vector<int> getVelocity();

    private:
     Object *obj_;
};
