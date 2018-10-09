cmake_minimum_required(VERSION 3.12)
project(List_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(List_1 src/main.cpp src/CTable.h src/CTable.cpp src/CRun.cpp src/CRun.h)

add_executable(Tests src/CTable.cpp test/CTableTests.cpp)