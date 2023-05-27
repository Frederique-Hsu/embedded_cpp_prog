# File name		: CMakeLists.txt
# Description	: 
#
#


cmake_minimum_required(VERSION 3.5)

project(conv)
add_executable(sender sender.cpp sender.hpp sender_main.cpp)
add_executable(receiver receiver.cpp receiver.hpp receiver_main.cpp)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

SET(CMAKE_CXX_FLAGS "--std=c++14")
set(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabihf-g++)
