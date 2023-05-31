set(TARGET_NAME homework05_test)

add_executable(${TARGET_NAME} 
                        main.cpp
                        ../merge_sort.cpp
                        sorting_test.cpp)

target_include_directories(${TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/homework05)
target_link_libraries(${TARGET_NAME} PRIVATE gtest_main gmock_main)

add_test(${TARGET_NAME} ${TARGET_NAME})