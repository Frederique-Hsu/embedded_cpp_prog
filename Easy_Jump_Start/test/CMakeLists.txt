cmake_minimum_required(VERSION 3.20)

set(CURRENT_PROJECT_NAME    UTest)
project(${CURRENT_PROJECT_NAME} LANGUAGES CXX)

set(CURRENT_PROJECT_ROOT_DIR    ${CMAKE_CURRENT_SOURCE_DIR})
set(CURRENT_PROJECT_BUILD_DIR   ${CURRENT_PROJECT_ROOT_DIR}/build)

file(GLOB_RECURSE sources 
    *.c*
    ../src/basic_classes_templates.cpp
    ../src/stl_container.cpp)
file(GLOB_RECURSE headers 
    *.h*
    ../src/basic_classes_templates.hpp
    ../src/stl_container.hpp)


include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

option(BUILD_UTFRAMEWORK_FROM_SRC
    "Git clone the repository of unit test framework from GitHub, and build it from source"
    ON)
if (${BUILD_UTFRAMEWORK_FROM_SRC})
    set(GTest_SOURCE_DIR    ${PROJECT_BUILD_DIR}/_deps/gtest-src)
    set(GTest_BUILD_DIR     ${PROJECT_BUILD_DIR}/_deps/gtest-build)

    FetchContent_Declare(GTest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             v1.15.2)
    
    FetchContent_GetProperties(GTest)
    if (NOT GTest_POPULATED)
        FetchContent_Populate(GTest)
        add_subdirectory(${GTest_SOURCE_DIR} ${GTest_BUILD_DIR})
    endif()
else()
    find_package(GTest REQUIRED CONFIG)
endif()


add_executable(${CURRENT_PROJECT_NAME} 
    ${sources}
    ${headers})
set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    CXX_STANDARD            14
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)
target_link_libraries(${CURRENT_PROJECT_NAME} PUBLIC gtest)
target_compile_options(${CURRENT_PROJECT_NAME} PUBLIC
    ${CXX_FLAGS}
    "-Wno-literal-suffix"
    "-Wno-unused-variable")


enable_testing()
add_test(NAME UTest_Firmware
    COMMAND $<TARGET_FILE:${CURRENT_PROJECT_NAME}>)

include(GoogleTest)
gtest_discover_tests(${CURRENT_PROJECT_NAME})