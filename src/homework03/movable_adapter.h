#pragma once

#include <vector>
#include "object.h"

class MovableAdapter{
    public:
     MovableAdapter(Object *obj);

     virtual std::vector<int> getPosition();
     virtual void setPosition(std::vector<int> pos);
     virtual std::vector<int> getVelocity();

    private:
     Object *obj_;
};
