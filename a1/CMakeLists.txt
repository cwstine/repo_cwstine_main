cmake_minimum_required(VERSION 3.17)
project(repo_cwstine_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)

add_executable(repo_cwstine_main
        include/DateException.h
        include/SimpleDate.h
        src/SimpleDate.cpp
        main.cpp
        main.h)
