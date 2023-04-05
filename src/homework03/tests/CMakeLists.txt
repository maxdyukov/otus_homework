set(TARGET_NAME homework03_test)

add_executable(${TARGET_NAME} main.cpp move_test.cpp object_mock.h)
target_include_directories(${TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/homework03)
target_link_libraries(${TARGET_NAME} PRIVATE gtest_main gmock_main)

add_test(${TARGET_NAME} ${TARGET_NAME})