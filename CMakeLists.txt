cmake_minimum_required(VERSION 3.28)
project(Modrinth_CPP)

set(CMAKE_CXX_STANDARD 20)
option(BUILD_TESTS "Build tests" ON)
#option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.hpp")

add_library(modrinth SHARED ${SOURCES} ${HEADERS})
add_library(modrinth-static STATIC ${SOURCES} ${HEADERS})

add_library(modrinth::shared ALIAS modrinth)
add_library(modrinth::static ALIAS modrinth-static)

target_include_directories(modrinth PUBLIC include)
target_include_directories(modrinth-static PUBLIC include)

target_link_libraries(modrinth PUBLIC cpr::cpr nlohmann_json::nlohmann_json)
target_link_libraries(modrinth-static PUBLIC cpr::cpr nlohmann_json::nlohmann_json)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()
