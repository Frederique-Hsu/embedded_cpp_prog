cmake_minimum_required(VERSION 3.20)

project(Easy_Jump_Start)


enable_testing()

if (${CMAKE_CXX_COMPILER} STREQUAL "/usr/bin/avr-g++")
    add_subdirectory(src)
elseif ((${CMAKE_CXX_COMPILER} STREQUAL "/usr/bin/g++") OR (${CMAKE_CXX_COMPILER} STREQUAL "/usr/bin/clang++-18"))
    add_subdirectory(test)
endif()