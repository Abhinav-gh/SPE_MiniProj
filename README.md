# Scientific Calculator

A C++ scientific calculator with simple assert-based unit testing and CMake build system.

## Features

- Basic arithmetic operations (add, subtract, multiply, divide)
- Square Root calculation
- Factorial calculation
- Natural Logarithm calculation
- Power function calculation
- Input validation and error handling
- Simple assert-based unit tests (no external dependencies)

## Current Project Structure

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
    └── test_harness.cpp    # Assert-based unit tests
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

Or run the test harness directly:
```bash
./calculator_test_harness
```

## Testing

The project includes simple assert-based unit tests covering:

- **Basic Arithmetic Tests**: Addition, subtraction, multiplication, division (including edge cases)
- **Square Root Tests**: Positive numbers, zero, negative inputs (error cases)
- **Factorial Tests**: Small numbers, negative inputs (error cases)
- **Natural Logarithm Tests**: Positive numbers, zero/negative inputs (error cases)
- **Power Function Tests**: Various base/exponent combinations, special cases
- **Edge Cases**: Boundary conditions and error handling

### Test Coverage

- Positive test cases for all mathematical operations
- Negative test cases for invalid inputs
- Edge cases and boundary conditions
- Error handling verification using exceptions

## CMake Targets

- `calculator_app`: Main calculator application
- `calculator_lib`: Calculator function library
- `calculator_test_harness`: Simple assert-based unit test executable
- `run_tests`: Custom target to run all tests

## Error Handling

The calculator implements robust error handling:

- Invalid input validation
- Mathematical domain errors (e.g., square root of negative numbers)
- Overflow detection for factorial calculations
- Floating-point validation for power operations
