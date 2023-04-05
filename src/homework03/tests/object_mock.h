#pragma once
#include "object.h"
#include <gmock/gmock.h>


class ObjectMock : public Object {
    public:
     ObjectMock() = default;
     MOCK_METHOD(int, getProperty, (const std::string &property), (override));
     MOCK_METHOD(void, setPosition, (std::vector<int> & position), (override));
     MOCK_METHOD(std::vector<int>, getPosition, (), (override));
};
