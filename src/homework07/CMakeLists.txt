set(TARGET homework07)

add_executable(${TARGET} main.cpp command_executor.cpp exception_handler.cpp
                         command_thread_run.cpp)

add_subdirectory(tests)
