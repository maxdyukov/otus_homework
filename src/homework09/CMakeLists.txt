set(TARGET_NAME homework09)

find_package(Boost REQUIRED COMPONENTS system json thread)
find_package(OpenSSL REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_library(${TARGET_NAME} create_game_request.cpp create_token_request.cpp)
target_link_libraries(${TARGET_NAME} PUBLIC OpenSSL::SSL OpenSSL::Crypto
                                            Boost::system
                                            Boost::json
                                            Boost::thread)

add_subdirectory(tests)