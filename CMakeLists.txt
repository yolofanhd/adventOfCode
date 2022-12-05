cmake_minimum_required(VERSION 3.0)
project(AdventOfCode2022)
add_executable(AdventOfCode2022 src/main.cpp)
target_link_libraries(${PROJECT_NAME} ncurses)
