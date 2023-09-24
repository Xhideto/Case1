cmake_minimum_required(VERSION 3.26)
project(oppai)

set(CMAKE_CXX_STANDARD 20)

add_executable(oppai main.cpp
        user.cpp
        user.h
        Ulogin.cpp)
