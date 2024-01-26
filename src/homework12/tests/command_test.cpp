#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "field.h"
#include "game_area.h"
#include "define_field_command.h"
#include "contex.h"

using namespace ::testing;

class MockObject : public Object {
public:
    MOCK_METHOD(int, getProperty, (const char*), (override));
    MOCK_METHOD(void, setProperty, (const char*, int), (override));
};


TEST(command_test, command) {
    Contex contex;
    MockObject *object = new MockObject;
    EXPECT_CALL(*object, getProperty(_)).WillRepeatedly(Return(1));

    contex.set("findObject", (Object*)object);
    contex.set("area_x", (size_t)10).set("area_y", (size_t)10)
          .set("width_neighborhood",(size_t)2).set("height_neighborhood",(size_t)2);
    GameArea *gameArea = new GameArea(&contex);
    gameArea->setObject(object);
    contex.set("game_area", gameArea);

    contex.set("isFindObject",false);
    DefineFieldCommand command(&contex);

    EXPECT_FALSE(std::any_cast<bool>(contex.get("isFindObject")));
    command.Handle();

    EXPECT_TRUE(std::any_cast<bool>(contex.get("isFindObject")));

    delete gameArea;
    delete object;
}