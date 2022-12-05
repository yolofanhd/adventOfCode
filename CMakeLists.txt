cmake_minimum_required(VERSION 3.0)
project(AdventOfCode1)
add_executable(AdventOfCode1 src/main.cpp)
target_link_libraries(${PROJECT_NAME} ncurses)
