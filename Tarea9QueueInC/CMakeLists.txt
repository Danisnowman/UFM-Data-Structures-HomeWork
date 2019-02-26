cmake_minimum_required(VERSION 3.13)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled src/main.c src/commonFunctions.c src/commonFunctions.h src/queue.c src/queue.h)