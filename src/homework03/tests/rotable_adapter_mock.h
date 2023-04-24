#include <gmock/gmock.h>
#include "rotable_adapter.h"

class RotatableAdapterMock : public RotatableAdapter {
  public:
  RotatableAdapterMock(Object *object) : RotatableAdapter(object){}
  MOCK_METHOD(int, getDirection, (), (override));
  MOCK_METHOD(int, getAngularVelocity, (), (override));
  MOCK_METHOD(int, getDirectionsNumber, (), (override));
};
