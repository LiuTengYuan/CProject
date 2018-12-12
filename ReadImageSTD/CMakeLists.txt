cmake_minimum_required(VERSION 3.10)
project(ReadImageSTD C)

set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../stb-master)

add_executable(ReadImageSTD main.c gfx.c gfx.h)
target_link_libraries(ReadImageSTD m X11)