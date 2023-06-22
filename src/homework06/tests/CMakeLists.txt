set(TARGET_NAME homework06_test)

add_executable(${TARGET_NAME} 
                        main.cpp
                        matrix_test.cpp
                        ../adapter.cpp
                        ../calculate_matrix.cpp
                        ../generate_matrix.cpp)

target_include_directories(${TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/homework06)
target_link_libraries(${TARGET_NAME} PRIVATE gtest_main gmock_main)

add_test(${TARGET_NAME} ${TARGET_NAME})