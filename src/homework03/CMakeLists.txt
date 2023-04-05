set(TARGET homework2)

add_library(${TARGET} 
                    move.h 
                    move.cpp 
                    movable_adapter.h 
                    movable_adapter.cpp 
                    object.h)

add_subdirectory(tests)