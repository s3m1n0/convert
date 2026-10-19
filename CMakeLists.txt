cmake_minimum_required(VERSION 3.10.0)
project(convert VERSION 0.1.0 LANGUAGES C)

set(SRC_CODE src/main.c)
add_executable(convert ${SRC_CODE})

