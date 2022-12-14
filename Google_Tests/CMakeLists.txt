cmake_minimum_required(VERSION 3.24)

# 'Google_test' is the subproject name
project(Google_Tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(COPY testTwoStrings.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY multiStrings.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run
        ../FileParser.hpp ../FileParser.cpp testParser.cpp
        ../TwoStringLCS.cpp ../TwoStringLCS.hpp testTwoStringLCS.cpp
        ../MultiStringLCS.cpp ../MultiStringLCS.hpp testMultiStringLCS.cpp)
add_executable(daDemo2 daDemo2.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main gmock gmock_main)