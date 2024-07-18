cmake_minimum_required(VERSION 3.28)
project(Modrinth_CPP)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

add_executable(Modrinth_CPP main.cpp)
target_link_libraries(Modrinth_CPP PRIVATE modrinth::static)
