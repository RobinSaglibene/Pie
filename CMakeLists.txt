cmake_minimum_required(VERSION 3.5)

project(TPC LANGUAGES C)
find_package(gd)
find_package(m)

add_executable(TPC main.c)
target_link_libraries(TPC gd m)

