cmake_minimum_required(VERSION 3.23)
project(Table C)

set(CMAKE_C_STANDARD 23)

add_executable(Table main.c)

add_subdirectory(includes)
target_link_libraries(Table includes)