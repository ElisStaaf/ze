cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "ze")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/usr/bin")
set(SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/ze.c")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -std=c99")

project(${PROJECT_NAME})

add_executable(ze ${SOURCE_FILES})
install(
    TARGETS "ze"
    DESTINATION "/usr/bin"
)
