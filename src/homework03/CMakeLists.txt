set(TARGET homework3)

add_library(${TARGET} 
                    move.h 
                    move.cpp 
                    movable_adapter.h 
                    movable_adapter.cpp 
                    object.h
                    object.cpp
                    rotable_adapter.cpp
                    rotable_adapter.h
                    rotate.cpp
                    rotate.h)                  

add_subdirectory(tests)