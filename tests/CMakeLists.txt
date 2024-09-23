cmake_minimum_required(VERSION 3.0)

project(tests)
add_subdirectory(lib/googletest-1.15.2)
include_directories(${GTEST_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS})
find_package(GTest REQUIRED)

set(SOURCE_FILES ActivityTest.cpp) #ActivityListTest.cpp)
add_executable(tests ${SOURCE_FILES})
target_link_libraries(tests {$GTEST_BOTH_LIBRARIES} core)