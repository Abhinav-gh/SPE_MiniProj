# Scientific Calculator - DevOps Pipeline Project

A comprehensive C++ scientific calculator with complete DevOps pipeline including CI/CD, containerization, and deployment automation.

## 🎯 Project Overview

This project implements a scientific calculator with the following operations:
- Basic arithmetic operations (add, subtract, multiply, divide)
- Square root function (√x)
- Factorial function (!x)  
- Natural logarithm (ln(x))
- Power function (x^b)

## 🏗️ DevOps Architecture

The complete DevOps pipeline includes:

1. **Source Control Management**: Git & GitHub
2. **Testing**: Assert-based unit tests
3. **Build**: CMake build system
4. **Continuous Integration**: Jenkins Pipeline
5. **Containerization**: Docker
6. **Container Registry**: Docker Hub
7. **Configuration Management**: Ansible
8. **Deployment**: Automated deployment to local/cloud hosts

## 📁 Project Structure

```
Calculator/
├── CMakeLists.txt              # Build configuration
├── Dockerfile                  # Container definition
├── Jenkinsfile                 # CI/CD pipeline
├── docker-compose.yml          # Multi-container setup
├── setup.sh                    # Environment setup script
├── README.md                   # Documentation
├── .gitignore                  # Git ignore rules
├── include/                    # Header files
│   └── calculator.h
├── src/                        # Source files
│   ├── calculator.cpp
│   └── main.cpp
├── tests/                      # Unit tests
│   └── test_harness.cpp
└── ansible/                    # Deployment automation
    ├── ansible.cfg
    ├── inventory
    └── deploy.yml
```

### Prerequisites

- CMake 3.14 or higher
- C++17 compatible compiler (GCC, Clang, MSVC)
- Docker and Docker Compose
- Jenkins (for CI/CD)
- Ansible (for deployment)

### Quick Start

1. **Clone and Setup:**
   ```bash
   git clone https://github.com/your-username/scientific-calculator
   cd scientific-calculator
   chmod +x setup.sh
   ./setup.sh
   ```

2. **Local Development:**
   ```bash
   # Build the project
   mkdir -p build && cd build
   cmake ..
   make -j$(nproc)
   
   # Run the calculator
   ./calculator_app
   
   # Run tests
   ./calculator_test_harness
   ```

3. **Docker Development:**
   ```bash
   # Build and run with Docker
   docker build -t scientific-calculator .
   docker run --rm -it scientific-calculator
   
   # Or use Docker Compose
   docker-compose up --build
   ```

## 🔄 DevOps Pipeline Stages

### 1. Source Control Management
- **Tool**: Git & GitHub
- **Purpose**: Version control and collaboration
- **Features**:
  - Branch protection rules
  - Pull request workflows
  - Issue tracking

### 2. Testing
- **Tool**: Custom assert-based test harness
- **Purpose**: Automated testing of all calculator functions
- **Coverage**:
  - Unit tests for all arithmetic operations
  - Edge case testing (division by zero, negative inputs)
  - Exception handling validation

### 3. Build
- **Tool**: CMake
- **Purpose**: Cross-platform build system
- **Outputs**:
  - `calculator_app`: Main application
  - `calculator_test_harness`: Test executable
  - `libcalculator_lib.a`: Static library

### 4. Continuous Integration
- **Tool**: Jenkins
- **Purpose**: Automated build, test, and deployment
- **Pipeline Stages**:
  - Checkout source code
  - Install dependencies
  - Build application
  - Run tests
  - Build Docker image
  - Push to registry
  - Deploy with Ansible

### 5. Containerization
- **Tool**: Docker
- **Purpose**: Application packaging and portability
- **Features**:
  - Multi-stage builds
  - Optimized image size
  - Health checks

### 6. Container Registry
- **Tool**: Docker Hub
- **Purpose**: Store and distribute container images
- **Tags**: `latest`, build numbers, version tags

### 7. Configuration Management & Deployment
- **Tool**: Ansible
- **Purpose**: Automated deployment and configuration
- **Features**:
  - Idempotent deployments
  - Multi-environment support
  - Container orchestration
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
