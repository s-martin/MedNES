cmake_minimum_required(VERSION 3.1...3.13)

if(${CMAKE_VERSION} VERSION_LESS 3.13)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.13)
endif()

project(MedNES VERSION 0.1 LANGUAGES CXX)


if(MSVC)
    add_definitions("/W4 /D_CRT_SECURE_NO_WARNINGS /permissive-")
else()
    add_definitions("-Wall -Wextra -pedantic")
endif()

find_package(SDL2 REQUIRED)

if(NOT MSVC) 
	set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

#enable_testing()
#include(CTest)

add_subdirectory(NES)
#add_subdirectory(test)
