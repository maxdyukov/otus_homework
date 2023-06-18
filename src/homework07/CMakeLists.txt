set(TARGET homework07)

add_executable(${TARGET} main.cpp command_executor.cpp exception_handler.cpp)

add_subdirectory(tests)
