set(TARGET homework1)

add_library(${TARGET} solve.cpp)

enable_testing()

add_subdirectory(tests)