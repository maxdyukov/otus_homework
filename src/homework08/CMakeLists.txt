set(TARGET_NAME homework08)

FetchContent_Declare(
  amqp-cpp
  GIT_REPOSITORY https://github.com/CopernicaMarketingSoftware/AMQP-CPP.git
  GIT_TAG        v4.3.26
)
FetchContent_MakeAvailable(amqp-cpp)
FetchContent_GetProperties(amqp-cpp)
if (NOT amqp-cpp_POPULATED)
    add_subdirectory(${amqp-cpp_SOURCE_DIR} ${amqp-cpp_BINARY_DIR})
endif()

find_package(Boost REQUIRED COMPONENTS system json thread)

include_directories(${Boost_INCLUDE_DIRS})

add_library(${TARGET_NAME} command_executor.cpp interpret_command.cpp)
target_link_libraries(${TARGET_NAME} PUBLIC 
                                            amqpcpp 
                                            Boost::system
                                            Boost::json
                                            Boost::thread)

add_subdirectory(tests)