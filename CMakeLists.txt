cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(cpp-webserver VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(webserver src/main.cpp ${SRC_FILES})

target_include_directories(webserver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
