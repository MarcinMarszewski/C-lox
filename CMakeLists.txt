cmake_minimum_required(VERSION 3.26)
project(Clox C)

set(CMAKE_C_STANDARD 11)

add_executable(Clox main.c
        src/common.h
        src/chunk.h
        src/chunk.c
        src/debug.h
        src/debug.c
        src/value.h
        src/value.c)
