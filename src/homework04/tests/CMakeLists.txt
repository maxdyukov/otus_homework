set(TARGET_NAME homework04_test)

add_executable(${TARGET_NAME} 
                        main.cpp 
                        ../check_fuel_command.cpp
                        ../exception_handler.cpp
                        ../logger_command.cpp
                        ../queue_command.cpp)

target_include_directories(${TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/homework03)
target_link_libraries(${TARGET_NAME} PRIVATE gtest_main gmock_main)

add_test(${TARGET_NAME} ${TARGET_NAME})