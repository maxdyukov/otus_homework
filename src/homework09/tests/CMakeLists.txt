set(TARGET_NAME homework09_test)

add_executable(${TARGET_NAME}
    main.cpp
    create_game_test.cpp
    create_token_test.cpp
    check_user_test.cpp
    ../create_game_request.cpp
    ../create_token_request.cpp
    ../check_user_request.cpp
)

target_include_directories(${TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/homework09)
target_link_libraries(${TARGET_NAME} PRIVATE gtest_main gmock_main OpenSSL::SSL OpenSSL::Crypto Boost::system Boost::json Boost::thread)

add_test(${TARGET_NAME} ${TARGET_NAME})