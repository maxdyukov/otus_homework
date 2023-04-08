#pragma once
#include "object.h"
#include <gmock/gmock.h>


class ObjectMock : public Object {
    public:
     ObjectMock() = default;
     MOCK_METHOD(int, getProperty, (const std::string &property), (override));
};
