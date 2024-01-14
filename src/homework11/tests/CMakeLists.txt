set(TARGET_NAME homework11_test)

add_executable(${TARGET_NAME} main.cpp command_executor_test.cpp
                              ../command_executor.cpp 
                              ../move_to_state.cpp
                              ../default_state.cpp
                              ../state.cpp)

target_include_directories(${TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/homework11)
target_link_libraries(${TARGET_NAME} PRIVATE gtest_main gmock_main)

add_test(${TARGET_NAME} ${TARGET_NAME})