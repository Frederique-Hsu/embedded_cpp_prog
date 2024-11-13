cmake_minimum_required(VERSION 3.20)

set(CURRENT_PROJECT_NAME LED_Blinking_Firmware)
project(${CURRENT_PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD              11)
set(CMAKE_CXX_EXTENSIONS            NO)
set(CMAKE_CXX_STANDARD_REQUIRED     YES)

set(PROJ_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJ_BUILD_DIR ${PROJ_ROOT_DIR}/build)

set(CMAKE_SYSTEM_PROCESSOR  avr)
if ("${CROSS_COMPILER}" STREQUAL "")
    set(CROSS_COMPILER "avr-")
endif()

set(CMAKE_C_COMPILER    "${CROSS_COMPILER}gcc")
set(CMAKE_CXX_COMPILER  "${CROSS_COMPILER}g++")
set(CMAKE_ASM_COMPILER  "${CROSS_COMPILER}as")

# C++ build options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -mmcu=atmega328p -fsigned-char -fno-exceptions")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -fstrict-enums -fno-use-cxa-atexit -fno-use-cxa-get-exception-ptr -fno-nonansi-builtins -fno-threadsafe-statics -fno-enforce-eh-specs")
# get rid of -rdynamic
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)


file(GLOB_RECURSE sources 
    mcal/*.c*
    mcal_memory/*.c*
    target/*.c*
    util/*.c*
    main.cpp
    led.cpp)
file(GLOB_RECURSE headers 
    mcal/*.h*
    mcal_memory/*.h*
    target/*.h*
    util/*.h*
    led.hpp)

set(CMAKE_EXECUTABLE_SUFFIX ".elf")

include_directories(includes
    mcal/avr
    util/STL
    util/utility)

add_executable(${CURRENT_PROJECT_NAME} 
    ${sources}
    ${headers}
    ${includes})
set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    LINK_FLAGS "-x none -mrelax -nostartfiles -Wl,--gc-sections -Wl,-T${PROJ_ROOT_DIR}/target/MCUs/avr/make/avr.ld,-Map,${PROJ_BUILD_DIR}/led.map")


set(target ${CURRENT_PROJECT_NAME})
set(target_with_suffix "${CURRENT_PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX}")

add_custom_command(TARGET ${target} POST_BUILD
    COMMENT "Extract    : executable hex file   : from ${target_with_suffix}"
    COMMAND ${CROSS_COMPILER}objcopy -O ihex $<TARGET_FILE:${target}> $<TARGET_FILE_DIR:${target}>/${target}.hex)

add_custom_command(TARGET ${target} POST_BUILD
    COMMENT "Extract    : assembly list file    : from ${target_with_suffix}"
    COMMAND ${CROSS_COMPILER}objdump --disassemble $<TARGET_FILE:${target}> > $<TARGET_FILE_DIR:${target}>/${target}.lss)

add_custom_command(TARGET ${target} POST_BUILD
    COMMENT "Extract    : size information      : from ${target_with_suffix}"
    COMMAND ${CROSS_COMPILER}size -A -t $<TARGET_FILE:${target}> > $<TARGET_FILE_DIR:${target}>/${target}_size.txt)

add_custom_command(TARGET ${target} POST_BUILD
    COMMENT "Extract    : name information      : from ${target_with_suffix}"
    COMMAND ${CROSS_COMPILER}nm --numeric-sort --print-size $<TARGET_FILE:${target}> > $<TARGET_FILE_DIR:${target}>/${target}_nm.txt)

add_custom_command(TARGET ${target} POST_BUILD
    COMMENT "Extract    : demangled names       : from ${target_with_suffix}"
    COMMAND ${CROSS_COMPILER}nm --numeric-sort --print-size $<TARGET_FILE:${target}> | ${CROSS_COMPILER}c++filt > $<TARGET_FILE_DIR:${target}>/${target}_cppfilt.txt)

