cmake_minimum_required(VERSION 3.28)
project(TodoList)

set(CMAKE_CXX_STANDARD 23)

add_executable(TodoList main.cpp
        Activity.cpp
        Activity.h
        ActivityList.cpp
        ActivityList.h
        TUI.cpp
        TUI.h)
