set(TARGET homework4)

add_library(${TARGET} 
                    queue_command.cpp
                    exception_handler.cpp
                    logger_command.cpp
                    check_fuel_command.cpp)                  

add_subdirectory(tests)