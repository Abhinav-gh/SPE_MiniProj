# tests/CMakeLists.txt

# Create test executable
add_executable(calculator_tests
    test_calculator.cpp
)

# Link with Google Test and calculator library
target_link_libraries(calculator_tests
    gtest_main
    calculator_lib
)

# Include Google Test for discovery
include(GoogleTest)
gtest_discover_tests(calculator_tests)