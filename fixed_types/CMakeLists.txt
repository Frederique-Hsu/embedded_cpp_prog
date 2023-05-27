# File name     : CMakeLists.txt
# Description   : This script tells how to build current project.
#
#


cmake_minimum_required(VERSION 3.6)

project(fixed_types)

add_executable(fixed_types fixed_types.cpp)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

SET(CMAKE_CXX_FLAGS "--std=c++11")
set(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabihf-g++)