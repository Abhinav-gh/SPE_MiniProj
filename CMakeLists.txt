cmake_minimum_required(VERSION 3.14)
project(Calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_BUILD_TYPE Release)

add_library(calculator_lib src/calculator.cpp)
target_include_directories(calculator_lib PUBLIC include)

add_executable(calculator_app src/main.cpp)
target_link_libraries(calculator_app calculator_lib)

add_executable(calculator_test_harness tests/test_harness.cpp)
target_link_libraries(calculator_test_harness calculator_lib)