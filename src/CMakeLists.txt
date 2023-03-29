project(OTUS_HOMEWORK)
cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fdata-sections -ffunction-sections -Wl,--gc-sections")
# set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -fdata-sections -ffunction-sections -Wl,--gc-sections")

find_package(GTest REQUIRED)
enable_testing()
add_subdirectory(homework01)
