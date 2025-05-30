cmake_minimum_required(VERSION  3.10)

set(CURRENT_PROJECT_NAME    firmware)
project(${CURRENT_PROJECT_NAME} LANGUAGES CXX)


file(GLOB_RECURSE sources "*.cpp")
file(GLOB_RECURSE headers "*.hpp")


add_executable(${CURRENT_PROJECT_NAME}
    ${sources}
    ${headers})
set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    CXX_STANDARD            17
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)
target_compile_options(${CURRENT_PROJECT_NAME} PUBLIC
    "-Wall"
    "-Wextra"
    "-Werror")
target_compile_definitions(${CURRENT_PROJECT_NAME} PUBLIC
    "LED_HIERARCHY")

#===============================================================================

set(PROJECT_NAME_DYNAMIC_POLYMORPHISM_PTR   dynamic_polymorphism_ptr)

add_executable(${PROJECT_NAME_DYNAMIC_POLYMORPHISM_PTR}
    ${sources}
    ${headers})
set_target_properties(${PROJECT_NAME_DYNAMIC_POLYMORPHISM_PTR} PROPERTIES
    CXX_STANDARD            17
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)
target_compile_options(${PROJECT_NAME_DYNAMIC_POLYMORPHISM_PTR} PUBLIC
    "-Wall"
    "-Wextra"
    "-Werror")
target_compile_definitions(${PROJECT_NAME_DYNAMIC_POLYMORPHISM_PTR} PUBLIC
    "DYNAMIC_POLYMORPHISM_PTR")

#===============================================================================

set(PROJECT_NAME_DYNAMIC_POLYMORPHISM_REF   dynamic_polymorphism_ref)

add_executable(${PROJECT_NAME_DYNAMIC_POLYMORPHISM_REF}
    ${sources}
    ${headers})
set_target_properties(${PROJECT_NAME_DYNAMIC_POLYMORPHISM_REF} PROPERTIES
    CXX_STANDARD            17
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)
target_compile_options(${PROJECT_NAME_DYNAMIC_POLYMORPHISM_REF} PUBLIC
    "-Wall"
    "-Wextra"
    "-Werror")
target_compile_definitions(${PROJECT_NAME_DYNAMIC_POLYMORPHISM_REF} PUBLIC
    "DYNAMIC_POLYMORPHISM_REF")