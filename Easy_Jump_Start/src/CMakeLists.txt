cmake_minimum_required(VERSION 3.20)

set(CURRENT_PROJECT_NAME    Firmware)
project(${CURRENT_PROJECT_NAME} LANGUAGES CXX)


set(CURRENT_PROJECT_ROOT_DIR    ${CMAKE_CURRENT_SOURCE_DIR})
set(CURRENT_PROJECT_BUILD_DIR   ${CURRENT_PROJECT_ROOT_DIR}/build)


SET(CMAKE_SYSTEM_COMPILER   avr)
if("${CROSS_COMPILER}" STREQUAL "")
    set(CROSS_COMPILER  "avr")
endif()

file(GLOB_RECURSE sources *.c*)
file(GLOB_RECURSE headers *.h*)

set(CMAKE_EXECUTABLE_SUFFIX     ".elf")

add_executable(${CURRENT_PROJECT_NAME} 
    ${sources}
    ${headers})
target_include_directories(${CURRENT_PROJECT_NAME} PRIVATE  
    ${CPPINCLUDES})
target_compile_options(${CURRENT_PROJECT_NAME} PUBLIC
    ${CXX_FLAGS}
    "-Wno-literal-suffix"
    "-mmcu=atmega328p"
    "-fsigned-char"
    "-fno-exceptions"
    "-fno-rtti"
    "-fstrict-enums"
    "-fno-use-cxa-atexit"
    "-fno-use-cxa-get-exception-ptr"
    "-fno-nonansi-builtins"
    "-fno-threadsafe-statics"
    "-fno-enforce-eh-specs")
set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    LINK_FLAGS
    "-x none -mrelax -nostartfiles -Wl,-T${CURRENT_PROJECT_ROOT_DIR}/avr.ld") # -Map,${CURRENT_PROJECT_BUILD_DIR}/${CURRENT_PROJECT_NAME}.map")
set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    CXX_STANDARD            17
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)

set(target  ${CURRENT_PROJECT_NAME})
set(target_with_suffix  ${CURRENT_PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX})


add_custom_command(TARGET ${target} POST_BUILD
    COMMENT "Extract : executable hex file \"${target}.hex\"        : from ${target_with_suffix}"
    COMMAND ${CROSS_COMPILER}-objcopy -O ihex $<TARGET_FILE:${target}> $<TARGET_FILE_DIR:${target}>/${target}.hex)

add_custom_command(TARGET ${target} POST_BUILD
    COMMENT "Extract : assembly list file \"${target}.lss\"         : from ${target_with_suffix}"
    COMMAND ${CROSS_COMPILER}-objdump --disassemble $<TARGET_FILE:${target}> > $<TARGET_FILE_DIR:${target}>/${target}.lss)

add_custom_command(TARGET ${target} POST_BUILD
    COMMENT "Extract : size information file \"${target}_size.txt\" : from ${target_with_suffix}"
    COMMAND ${CROSS_COMPILER}-size -A -t $<TARGET_FILE:${target}> > $<TARGET_FILE_DIR:${target}>/${target}_size.txt)

add_custom_command(TARGET ${target} POST_BUILD
    COMMENT "Extract : name information file \"${target}_name.txt\" : from ${target_with_suffix}"
    COMMAND ${CROSS_COMPILER}-nm --numeric-sort --print-size $<TARGET_FILE:${target}> > $<TARGET_FILE_DIR:${target}>/${target}_name.txt)

add_custom_command(TARGET ${target} POST_BUILD
    COMMENT "Extract : damangled names \"${target}_cppfilt.txt\"    : from ${target_with_suffix}"
    COMMAND ${CROSS_COMPILER}-nm --numeric-sort --print-size $<TARGET_FILE:${target}> | 
            ${CROSS_COMPILER}-c++filt > $<TARGET_FILE_DIR:${target}>/${target}_cppfilt.txt )

