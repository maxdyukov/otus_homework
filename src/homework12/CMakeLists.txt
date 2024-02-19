set(TARGET_NAME homework12)

add_library(${TARGET_NAME} field.cpp game_area.cpp define_field_command.h)

add_subdirectory(tests)
