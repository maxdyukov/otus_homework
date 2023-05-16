#pragma once
#include "object.h"
#include <gmock/gmock.h>

class ObjectMock : public Object {
    public:
     MOCK_METHOD(int, getProperty, (const char*), (override));
     MOCK_METHOD(void, setProperty, (const char*, int), (override));
};