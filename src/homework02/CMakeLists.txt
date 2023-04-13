set(TARGET homework2)

add_library(${TARGET} STATIC 
                      src/check_fuel_command.cpp
                      src/burn_fuel_command.cpp)           

add_subdirectory(tests)