# Scientific Calculator

A C++ scientific calculator with comprehensive unit testing using Google Test and CMake build system.

## Features

- Square Root calculation
- Factorial calculation
- Natural Logarithm calculation
- Power function calculation
- Input validation and error handling
- Comprehensive unit tests

## Current project Structure

```
Calculator/
├── CMakeLists.txt          # Main CMake configuration
├── README.md               # Project documentation
├── .gitignore              # Git ignore file
├── build/                  # Build directory (generated)
├── include/                # Header files
│   └── calculator.h        # Calculator function declarations
├── src/                    # Source files
│   ├── calculator.cpp      # Calculator implementations
│   └── main.cpp           # Main application entry point
└── tests/                  # Unit tests
    ├── CMakeLists.txt      # Test CMake configuration
    └── test_calculator.cpp # Google Test unit tests
```

## Building the Project

### Prerequisites

- CMake 3.14 or higher
- C++17 compatible compiler (GCC, Clang, MSVC)
- Internet connection (for downloading Google Test)

### Build Steps

1. Create and navigate to build directory:
   ```bash
   mkdir -p build && cd build
   ```

2. Configure the project:
   ```bash
   cmake ..
   ```

3. Build the project:
   ```bash
   make -j$(nproc)
   ```

### Running the Application

After building, run the calculator:
```bash
./calculator_app
```

### Running Tests

Run all unit tests:
```bash
make run_tests
```

Or run tests with CTest:
```bash
ctest --verbose
```

Or run the test executable directly:
```bash
./calculator_tests
```

## Testing

The project includes comprehensive unit tests covering:

- **Square Root Tests**: Positive numbers, zero, decimals, negative inputs (error cases)
- **Factorial Tests**: Small numbers, large numbers, negative inputs, overflow cases
- **Natural Logarithm Tests**: Positive numbers, decimals, zero/negative inputs (error cases)
- **Power Function Tests**: Various base/exponent combinations, special cases, edge cases
- **Performance Tests**: Ensuring reasonable execution time for operations
- **Edge Cases**: Boundary conditions and error handling

### Test Coverage

- Positive test cases for all mathematical operations
- Negative test cases for invalid inputs
- Edge cases and boundary conditions
- Error handling verification using exceptions
- Performance validation

## CMake Targets

- `calculator_app`: Main calculator application
- `calculator_lib`: Calculator function library
- `calculator_tests`: Unit test executable
- `run_tests`: Custom target to run all tests

## Error Handling

The calculator implements robust error handling:

- Invalid input validation
- Mathematical domain errors (e.g., square root of negative numbers)
- Overflow detection for factorial calculations
- Floating-point validation for power operations
