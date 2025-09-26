// test_calculator.cpp

#include <gtest/gtest.h>
#include <cmath>
#include <stdexcept>
#include <chrono>
#include "../include/calculator.h"

// Test fixture class for Calculator tests
class CalculatorTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Setup code for each test
    }

    void TearDown() override
    {
        // Cleanup code for each test
    }

    // Helper function to compare floating point numbers
    bool isClose(double a, double b, double tolerance = 1e-9)
    {
        return std::abs(a - b) < tolerance;
    }
};

// Square Root Tests
TEST_F(CalculatorTest, SquareRootPositiveNumbers)
{
    EXPECT_TRUE(isClose(calculateSquareRoot(4.0), 2.0));
    EXPECT_TRUE(isClose(calculateSquareRoot(9.0), 3.0));
    EXPECT_TRUE(isClose(calculateSquareRoot(16.0), 4.0));
    EXPECT_TRUE(isClose(calculateSquareRoot(25.0), 5.0));
    EXPECT_TRUE(isClose(calculateSquareRoot(2.0), 1.414213562373095));
}

TEST_F(CalculatorTest, SquareRootZero)
{
    EXPECT_TRUE(isClose(calculateSquareRoot(0.0), 0.0));
}

TEST_F(CalculatorTest, SquareRootDecimalNumbers)
{
    EXPECT_TRUE(isClose(calculateSquareRoot(0.25), 0.5));
    EXPECT_TRUE(isClose(calculateSquareRoot(0.16), 0.4));
    EXPECT_TRUE(isClose(calculateSquareRoot(1.21), 1.1));
}

TEST_F(CalculatorTest, SquareRootNegativeNumbers)
{
    EXPECT_THROW(calculateSquareRoot(-1.0), std::invalid_argument);
    EXPECT_THROW(calculateSquareRoot(-4.0), std::invalid_argument);
    EXPECT_THROW(calculateSquareRoot(-0.1), std::invalid_argument);
}

// Factorial Tests
TEST_F(CalculatorTest, FactorialPositiveNumbers)
{
    EXPECT_EQ(calculateFactorial(0), 1);
    EXPECT_EQ(calculateFactorial(1), 1);
    EXPECT_EQ(calculateFactorial(2), 2);
    EXPECT_EQ(calculateFactorial(3), 6);
    EXPECT_EQ(calculateFactorial(4), 24);
    EXPECT_EQ(calculateFactorial(5), 120);
    EXPECT_EQ(calculateFactorial(6), 720);
    EXPECT_EQ(calculateFactorial(10), 3628800);
}

TEST_F(CalculatorTest, FactorialLargeNumbers)
{
    EXPECT_EQ(calculateFactorial(15), 1307674368000LL);
    EXPECT_EQ(calculateFactorial(20), 2432902008176640000LL);
}

TEST_F(CalculatorTest, FactorialNegativeNumbers)
{
    EXPECT_THROW(calculateFactorial(-1), std::invalid_argument);
    EXPECT_THROW(calculateFactorial(-5), std::invalid_argument);
    EXPECT_THROW(calculateFactorial(-10), std::invalid_argument);
}

TEST_F(CalculatorTest, FactorialOverflow)
{
    EXPECT_THROW(calculateFactorial(21), std::overflow_error);
    EXPECT_THROW(calculateFactorial(25), std::overflow_error);
    EXPECT_THROW(calculateFactorial(100), std::overflow_error);
}

// Natural Logarithm Tests
TEST_F(CalculatorTest, NaturalLogPositiveNumbers)
{
    EXPECT_TRUE(isClose(calculateNaturalLog(1.0), 0.0));
    EXPECT_TRUE(isClose(calculateNaturalLog(M_E), 1.0));
    EXPECT_TRUE(isClose(calculateNaturalLog(M_E * M_E), 2.0));
    EXPECT_TRUE(isClose(calculateNaturalLog(10.0), 2.302585092994046));
    EXPECT_TRUE(isClose(calculateNaturalLog(2.0), 0.6931471805599453));
}

TEST_F(CalculatorTest, NaturalLogDecimalNumbers)
{
    EXPECT_TRUE(isClose(calculateNaturalLog(0.5), -0.6931471805599453));
    EXPECT_TRUE(isClose(calculateNaturalLog(0.1), -2.302585092994046));
    EXPECT_TRUE(calculateNaturalLog(0.01) < 0);
}

TEST_F(CalculatorTest, NaturalLogInvalidInputs)
{
    EXPECT_THROW(calculateNaturalLog(0.0), std::invalid_argument);
    EXPECT_THROW(calculateNaturalLog(-1.0), std::invalid_argument);
    EXPECT_THROW(calculateNaturalLog(-0.5), std::invalid_argument);
    EXPECT_THROW(calculateNaturalLog(-10.0), std::invalid_argument);
}

// Power Function Tests
TEST_F(CalculatorTest, PowerPositiveBase)
{
    EXPECT_TRUE(isClose(calculatePower(2.0, 3.0), 8.0));
    EXPECT_TRUE(isClose(calculatePower(3.0, 2.0), 9.0));
    EXPECT_TRUE(isClose(calculatePower(5.0, 0.0), 1.0));
    EXPECT_TRUE(isClose(calculatePower(10.0, 2.0), 100.0));
    EXPECT_TRUE(isClose(calculatePower(4.0, 0.5), 2.0));
}

TEST_F(CalculatorTest, PowerNegativeBase)
{
    EXPECT_TRUE(isClose(calculatePower(-2.0, 2.0), 4.0));
    EXPECT_TRUE(isClose(calculatePower(-2.0, 3.0), -8.0));
    EXPECT_TRUE(isClose(calculatePower(-3.0, 2.0), 9.0));
    EXPECT_TRUE(isClose(calculatePower(-1.0, 2.0), 1.0));
}

TEST_F(CalculatorTest, PowerNegativeExponent)
{
    EXPECT_TRUE(isClose(calculatePower(2.0, -1.0), 0.5));
    EXPECT_TRUE(isClose(calculatePower(2.0, -2.0), 0.25));
    EXPECT_TRUE(isClose(calculatePower(10.0, -1.0), 0.1));
    EXPECT_TRUE(isClose(calculatePower(4.0, -0.5), 0.5));
}

TEST_F(CalculatorTest, PowerSpecialCases)
{
    EXPECT_TRUE(isClose(calculatePower(0.0, 5.0), 0.0));
    EXPECT_TRUE(isClose(calculatePower(1.0, 100.0), 1.0));
    EXPECT_TRUE(isClose(calculatePower(100.0, 0.0), 1.0));
}

TEST_F(CalculatorTest, PowerDecimalNumbers)
{
    EXPECT_TRUE(isClose(calculatePower(2.5, 2.0), 6.25));
    EXPECT_TRUE(isClose(calculatePower(1.5, 3.0), 3.375));
    EXPECT_TRUE(isClose(calculatePower(0.5, 2.0), 0.25));
}

// Edge cases and boundary tests
TEST_F(CalculatorTest, EdgeCases)
{
    // Very small positive numbers
    EXPECT_NO_THROW(calculateSquareRoot(1e-10));
    EXPECT_NO_THROW(calculateNaturalLog(1e-10));

    // Large numbers (within reasonable range)
    EXPECT_NO_THROW(calculateSquareRoot(1e10));
    EXPECT_NO_THROW(calculatePower(10.0, 10.0));
}

// Performance test for factorial with valid range
TEST_F(CalculatorTest, FactorialPerformance)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i <= 20; ++i)
    {
        calculateFactorial(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Should complete within reasonable time (less than 100ms)
    EXPECT_LT(duration.count(), 100);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}