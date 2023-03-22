set(TARGET homework1)

add_library(${TARGET} solve.cpp)

add_subdirectory(tests)