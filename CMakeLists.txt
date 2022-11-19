cmake_minimum_required(VERSION 3.24)
project(cop4534_p5)

set(CMAKE_CXX_STANDARD 14)

add_executable(cop4534_p5 main.cpp
        FileParser.cpp FileParser.hpp)

file(COPY multiStrings.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY twoStrings.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(Google_Tests)