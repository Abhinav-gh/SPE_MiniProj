// calculator.cpp
// Core calculator functionality - pure calculation logic only

#include "../include/calculator.h"
#include <cmath>
#include <stdexcept>

using namespace std;

// Square root calculation
double calculateSquareRoot(double num)
{
    if (num < 0)
    {
        throw invalid_argument("Square root of negative number is not defined");
    }
    return sqrt(num);
}

// Factorial calculation
long long calculateFactorial(int num)
{
    if (num < 0)
    {
        throw invalid_argument("Factorial is not defined for negative numbers");
    }
    if (num > 20)
    {
        throw overflow_error("Factorial too large for long long");
    }

    long long result = 1;
    for (int i = 1; i <= num; ++i)
    {
        result *= i;
    }
    return result;
}

// Natural logarithm calculation
double calculateNaturalLog(double num)
{
    if (num <= 0)
    {
        throw invalid_argument("Natural logarithm is only defined for positive numbers");
    }
    return log(num);
}

// Power function calculation
double calculatePower(double base, double exponent)
{
    double result = pow(base, exponent);
    if (!isfinite(result))
    {
        throw overflow_error("Power operation resulted in overflow or invalid result");
    }
    return result;
}
