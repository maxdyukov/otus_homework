set(TARGET_NAME solve_tests)

add_executable(${TARGET_NAME} main.cpp solve_tests.cpp ../solve.cpp)
target_include_directories(${TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIR})
target_link_libraries(${TARGET_NAME} PRIVATE gtest_main)

add_test(${TARGET_NAME} ${TARGET_NAME})