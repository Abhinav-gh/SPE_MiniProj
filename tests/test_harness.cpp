// test_harness.cpp - Simple assert-based test harness

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "../include/calculator.h"

// Helper function to compare floating point numbers with tolerance
bool isClose(double a, double b, double tolerance = 1e-9)
{
    return std::abs(a - b) < tolerance;
}

void testAdd()
{
    std::cout << "Testing add function..." << std::endl;

    // Positive numbers
    assert(add(2, 3) == 5);
    assert(add(10, 20) == 30);

    // Negative numbers
    assert(add(-1, -1) == -2);
    assert(add(-5, 3) == -2);

    // Edge cases
    assert(add(0, 0) == 0);
    assert(add(0, 5) == 5);

    std::cout << "✓ All add tests passed!" << std::endl;
}

void testSubtract()
{
    std::cout << "Testing subtract function..." << std::endl;

    // Positive numbers
    assert(subtract(5, 3) == 2);
    assert(subtract(10, 7) == 3);

    // Negative numbers
    assert(subtract(-2, -2) == 0);
    assert(subtract(-5, -10) == 5);

    // Edge cases
    assert(subtract(0, 5) == -5);
    assert(subtract(5, 0) == 5);

    std::cout << "✓ All subtract tests passed!" << std::endl;
}

void testMultiply()
{
    std::cout << "Testing multiply function..." << std::endl;

    // Positive numbers
    assert(multiply(2, 3) == 6);
    assert(multiply(4, 5) == 20);

    // Negative numbers
    assert(multiply(-2, 3) == -6);
    assert(multiply(-2, -3) == 6);

    // Edge cases
    assert(multiply(0, 100) == 0);
    assert(multiply(1, 5) == 5);

    std::cout << "✓ All multiply tests passed!" << std::endl;
}

void testDivide()
{
    std::cout << "Testing divide function..." << std::endl;

    // Positive numbers
    assert(divide(6, 3) == 2);
    assert(divide(20, 4) == 5);

    // Negative numbers
    assert(divide(-6, 3) == -2);
    assert(divide(-6, -3) == 2);

    // Division by zero test
    bool exceptionCaught = false;
    try
    {
        divide(5, 0);
        assert(false && "Should have thrown exception for division by zero");
    }
    catch (const std::invalid_argument &)
    {
        exceptionCaught = true;
    }
    assert(exceptionCaught);

    std::cout << "✓ All divide tests passed!" << std::endl;
}

void testSquareRoot()
{
    std::cout << "Testing square root function..." << std::endl;

    // Positive numbers
    assert(isClose(calculateSquareRoot(4.0), 2.0));
    assert(isClose(calculateSquareRoot(9.0), 3.0));
    assert(isClose(calculateSquareRoot(16.0), 4.0));

    // Zero
    assert(isClose(calculateSquareRoot(0.0), 0.0));

    // Negative number test (should throw exception)
    bool exceptionCaught = false;
    try
    {
        calculateSquareRoot(-1.0);
        assert(false && "Should have thrown exception for negative square root");
    }
    catch (const std::invalid_argument &)
    {
        exceptionCaught = true;
    }
    assert(exceptionCaught);

    std::cout << "✓ All square root tests passed!" << std::endl;
}

void testFactorial()
{
    std::cout << "Testing factorial function..." << std::endl;

    // Small positive numbers
    assert(calculateFactorial(0) == 1);
    assert(calculateFactorial(1) == 1);
    assert(calculateFactorial(5) == 120);

    // Negative number test (should throw exception)
    bool exceptionCaught = false;
    try
    {
        calculateFactorial(-1);
        assert(false && "Should have thrown exception for negative factorial");
    }
    catch (const std::invalid_argument &)
    {
        exceptionCaught = true;
    }
    assert(exceptionCaught);

    std::cout << "✓ All factorial tests passed!" << std::endl;
}

void testNaturalLog()
{
    std::cout << "Testing natural logarithm function..." << std::endl;

    // Positive numbers
    assert(isClose(calculateNaturalLog(1.0), 0.0));
    assert(isClose(calculateNaturalLog(M_E), 1.0));

    // Invalid input test (should throw exception)
    bool exceptionCaught = false;
    try
    {
        calculateNaturalLog(0.0);
        assert(false && "Should have thrown exception for log(0)");
    }
    catch (const std::invalid_argument &)
    {
        exceptionCaught = true;
    }
    assert(exceptionCaught);

    exceptionCaught = false;
    try
    {
        calculateNaturalLog(-1.0);
        assert(false && "Should have thrown exception for log(negative)");
    }
    catch (const std::invalid_argument &)
    {
        exceptionCaught = true;
    }
    assert(exceptionCaught);

    std::cout << "✓ All natural log tests passed!" << std::endl;
}

void testPower()
{
    std::cout << "Testing power function..." << std::endl;

    // Basic power operations
    assert(isClose(calculatePower(2.0, 3.0), 8.0));
    assert(isClose(calculatePower(3.0, 2.0), 9.0));
    assert(isClose(calculatePower(5.0, 0.0), 1.0));

    // Negative base
    assert(isClose(calculatePower(-2.0, 2.0), 4.0));
    assert(isClose(calculatePower(-2.0, 3.0), -8.0));

    std::cout << "✓ All power tests passed!" << std::endl;
}

int main()
{
    std::cout << "Running Calculator Test Harness..." << std::endl;
    std::cout << "=================================" << std::endl;

    try
    {
        // Test basic arithmetic functions
        testAdd();
        testSubtract();
        testMultiply();
        testDivide();

        // Test advanced functions
        testSquareRoot();
        testFactorial();
        testNaturalLog();
        testPower();

        std::cout << std::endl;
        std::cout << "🎉 ALL CALCULATOR TESTS PASSED SUCCESSFULLY! 🎉" << std::endl;
        std::cout << "=================================" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "❌ Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cout << "❌ Test failed with unknown exception" << std::endl;
        return 1;
    }

    return 0;
}