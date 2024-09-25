cmake_minimum_required(VERSION 3.0)

project(tests)

include_directories(${GTEST_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS} ${GTEST_DIR})


find_package(GTest CONFIG REQUIRED)


set(SOURCE_FILES ActivityTestFixture.cpp
        ActivityListTestsFixture.cpp
        RunTests.cpp
        ActivityTest.cpp)
add_executable(tests ${SOURCE_FILES})
target_link_libraries(tests GTest::gtest GTest::gtest_main core GTest::gmock GTest::gmock_main ${GTEST_LIBRARIES})