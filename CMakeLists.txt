cmake_minimum_required(VERSION 3.14)
project(Calculator VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(include)

# Create library for calculator functions
add_library(calculator_lib 
    src/calculator.cpp
)

target_include_directories(calculator_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Create main executable
add_executable(calculator_app
    src/main.cpp
)

target_link_libraries(calculator_app calculator_lib)

# Create test harness executable
add_executable(calculator_test_harness
    tests/test_harness.cpp
)

target_link_libraries(calculator_test_harness calculator_lib)

# Create a custom target to run tests
add_custom_target(run_tests
    COMMAND ./calculator_test_harness
    DEPENDS calculator_test_harness
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)