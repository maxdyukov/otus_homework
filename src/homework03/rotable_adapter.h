#pragma once

#include "object.h"

class RotatableAdapter {
    public:
     explicit RotatableAdapter(Object *object);
     virtual void setDirectory(int directory);
     virtual int getDirection();
     virtual int getAngularVelocity();
     virtual int getDirectionsNumber();
    private:
     Object *object_;
};