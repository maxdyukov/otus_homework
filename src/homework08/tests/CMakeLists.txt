set(TARGET_NAME homework08_test)

add_executable(${TARGET_NAME}
    main.cpp
    interpret_command_test.cpp
    ../interpret_command.cpp
    ../command_executor.cpp
)

target_include_directories(${TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/homework08)
target_link_libraries(${TARGET_NAME} PRIVATE gtest_main gmock_main amqpcpp Boost::system Boost::json Boost::thread)

add_test(${TARGET_NAME} ${TARGET_NAME})