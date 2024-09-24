cmake_minimum_required(VERSION 3.0)

project(tests)

include_directories(${GTEST_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS})

find_package(GTest CONFIG REQUIRED)


set(SOURCE_FILES ActivityTest.cpp
        ActivityListTests.cpp)
add_executable(tests ${SOURCE_FILES})
target_link_libraries(tests {$GTEST_BOTH_LIBRARIES} GTest::gtest GTest::gtest_main core)