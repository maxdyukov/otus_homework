set(TARGET_NAME homework03_test)

add_executable(${TARGET_NAME} 
                        main.cpp 
                        move_test.cpp 
                        movable_adapter_mock.h 
                        object_mock.h
                        ../movable_adapter.cpp
                        ../move.cpp
                        ../object.cpp)

target_include_directories(${TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/homework03)
target_link_libraries(${TARGET_NAME} PRIVATE gtest_main gmock_main)

add_test(${TARGET_NAME} ${TARGET_NAME})