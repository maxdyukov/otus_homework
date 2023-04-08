#pragma once

#include "rotable_adapter.h"

class Rotate {
    public:
     explicit Rotate(RotatableAdapter *adapter);
     void Execute();
    private:
     RotatableAdapter *adapter_;
};