cmake_minimum_required(VERSION 3.20)

project(embedded_cpp_prog)

list(APPEND CXX_FLAGS
    "-Wall"
    "-Wextra"
    "-pedantic"
    "-Werror")

set(PROJECT_ROOT_DIR    ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_BUILD_DIR   ${PROJECT_ROOT_DIR}/build)


set(CPPINCLUDES   "${PROJECT_ROOT_DIR}/avr-libstdcpp/include")




enable_testing()

add_subdirectory(Easy_Jump_Start)
if (${CMAKE_CXX_COMPILER} STREQUAL "/usr/bin/avr-g++")
    add_subdirectory(LED_Blinking_Firmware)
endif()