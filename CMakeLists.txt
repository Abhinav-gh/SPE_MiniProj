cmake_minimum_required(VERSION 3.14)
project(Calculator LANGUAGES CXX)

# C++17 standard and static linking
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_BUILD_TYPE Release)

# Calculator library
add_library(calculator_lib src/calculator.cpp)
target_include_directories(calculator_lib PUBLIC include)

# Main calculator application
add_executable(calculator_app src/main.cpp)
target_link_libraries(calculator_app calculator_lib)

# Test harness
add_executable(calculator_test_harness tests/test_harness.cpp)
target_link_libraries(calculator_test_harness calculator_lib)

# Custom target for Jenkins CI/CD
add_custom_target(run_tests
    COMMAND ./calculator_test_harness
    DEPENDS calculator_test_harness
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)