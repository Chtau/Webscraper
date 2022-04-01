cmake_minimum_required(VERSION 3.0)

project("Webscraper")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out) 
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

include(FindPkgConfig)
pkg_check_modules(CURLPP REQUIRED curlpp)

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE ExamplesFileList "src/*.cpp")

add_executable(webscraper ${ExamplesFileList})

target_link_libraries(webscraper ${CURLPP_LDFLAGS})