cmake_minimum_required(VERSION 3.14)
project(OTUS_HOMEWORK)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)
FetchContent_GetProperties(googletest)
if (NOT googletest_POPULATED)
    add_subdirectory(${googletest_SOURCE_DIR} ${google_BINARY_DIR})
endif()

enable_testing()
add_subdirectory(homework01)
add_subdirectory(homework02)
add_subdirectory(homework03)
add_subdirectory(homework04)
add_subdirectory(homework05)
add_subdirectory(homework06)
add_subdirectory(homework07)
add_subdirectory(homework08)
