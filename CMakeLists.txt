cmake_minimum_required(VERSION 3.5.0)
project(lab1 VERSION 0.1.0 LANGUAGES C CXX)
include_directories(src)



set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_CXX_FLAGS "-Wall -Wextra -g")

add_executable(lab1 main.cpp ./src/funcs.cpp ./src/input.cpp)
target_include_directories(lab1 PUBLIC src)

