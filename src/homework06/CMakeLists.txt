set(TARGET_NAME homework06)

add_library(prog1 calculate_matrix.cpp)
add_library(prog2 generate_matrix.cpp adapter.cpp)

add_subdirectory(tests)
