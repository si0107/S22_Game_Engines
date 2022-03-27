cmake_minimum_required(VERSION 3.16)

project(GameProj)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DPIGU_WINDOWS)
elseif(APPLE)
	add_definitions(-DPIGU_MACOS)
elseif(UNIX)
	add_definitions(-DPIGU_LINUX)
endif()

add_subdirectory(GameProj)
add_subdirectory(Pigu)
add_subdirectory(glfw)