set(TARGET_NAME homework2_test)

add_executable(${TARGET_NAME} 
                    main.cpp 
                    ${CMAKE_SOURCE_DIR}/homework02/src/check_fuel_command.cpp
                    ${CMAKE_SOURCE_DIR}/homework02/src/burn_fuel_command.cpp
                    ${CMAKE_SOURCE_DIR}/homework02/src/macro_command.cpp
                    ${CMAKE_SOURCE_DIR}/homework02/src/change_velocity_command.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/check_fuel_command_test.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/burn_fuel_command_test.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/macro_command_test.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/change_velocity_command_test.cpp
        )
target_include_directories(${TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/homework02/src/)
target_link_libraries(${TARGET_NAME} PRIVATE gtest_main gmock_main)

add_test(${TARGET_NAME} ${TARGET_NAME})