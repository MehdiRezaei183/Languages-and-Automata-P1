cmake_minimum_required(VERSION 3.27)
project(PasswordNFA)

set(CMAKE_CXX_STANDARD 17)

add_executable(PasswordNFA main.cpp
        System/system.cpp
        System/transition/transition.h
        System/State/state.h
        System/State/state.cpp
        System/transition/transition.cpp)
