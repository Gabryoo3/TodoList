cmake_minimum_required(VERSION 3.5)
project(TodoList)

set(CMAKE_CXX_STANDARD 23)
add_subdirectory(tests)
set(SOURCE_FILES Activity.cpp ActivityList.cpp Activity.h ActivityList.h TUI.cpp TUI.h
        Observer.h
        Observer.cpp
)
add_executable(TodoList main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(TodoList core)
