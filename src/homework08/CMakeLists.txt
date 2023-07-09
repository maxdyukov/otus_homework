set(TARGET_NAME homework08)

if(APPLE)
  set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/amqp-cpp/4.3.26/cmake")
endif(APPLE)

find_package(amqpcpp CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS system json thread)

include_directories(${Boost_INCLUDE_DIRS})

add_library(${TARGET_NAME} command_executor.cpp interpret_command.cpp)
target_link_libraries(${TARGET_NAME} PUBLIC 
                                            amqpcpp 
                                            Boost::system
                                            Boost::json
                                            Boost::thread)

add_subdirectory(tests)