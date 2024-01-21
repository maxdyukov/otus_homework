set(TARGET_NAME homework12)

add_library(${TARGET_NAME} field.cpp game_area.cpp)

add_subdirectory(tests)
