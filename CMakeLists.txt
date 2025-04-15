cmake_minimum_required(VERSION 3.30)
project(thirdCompilerLab)

set(CMAKE_CXX_STANDARD 23)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(thirdCompilerLab
        src/parser/Parser.cpp
        src/parser/Parser.h
        src/main.cpp
        src/tests/Gtests.cpp)


target_link_libraries(thirdCompilerLab
        ${GTEST_LIBRARIES}
        pthread
)