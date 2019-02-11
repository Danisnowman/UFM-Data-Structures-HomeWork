cmake_minimum_required(VERSION 3.13)
project(Tarea7AreaOfShape C)

set(CMAKE_C_STANDARD 11)

add_executable(Tarea7AreaOfShape src/main/main.c src/main/shape.c src/main/shape.h src/main/commonFunctions.c src/main/commonFunctions.h src/test/tests.c src/test/tests.h)
include_directories(src/test/googletest/googletest/include)

#target_link_libraries(gtest gtest_main)
if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)