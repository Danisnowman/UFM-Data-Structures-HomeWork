cmake_minimum_required(VERSION 3.13)
project(Tarea9QueueInC C)

set(CMAKE_C_STANDARD 11)

add_executable(Tarea9QueueInC src/main.c src/commonFunctions.c src/commonFunctions.h src/queue.c src/queue.h src/worker.c src/worker.h src/merger.c src/merger.h)