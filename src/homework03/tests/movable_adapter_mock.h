#pragma once
#include <gmock/gmock.h>
#include "movable_adapter.h"

class MovableAdapterMock : public MovableAdapter {
    public:
     MovableAdapterMock(Object *a_object) : MovableAdapter(a_object){}
     MOCK_METHOD(std::vector<int>, getPosition, (), (override));
     MOCK_METHOD(std::vector<int>, getVelocity, (), (override));
};

class MovableAdapterWithVelocityMock : public MovableAdapter {
    public:
     MovableAdapterWithVelocityMock(Object *a_object) : MovableAdapter(a_object){}
     MOCK_METHOD(std::vector<int>, getPosition, (), (override));
};
