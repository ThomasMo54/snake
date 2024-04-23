cmake_minimum_required(VERSION 3.28)
project(snake)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(snake main.cpp)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})