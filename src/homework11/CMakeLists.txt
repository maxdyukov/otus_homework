set(TARGET_NAME homework11)

set(CMAKE_CXX_STANDARD 17)

add_library(${TARGET_NAME} command_executor.cpp state.cpp default_state.cpp move_to_state.cpp)

add_subdirectory(tests)
