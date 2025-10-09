// Simple test harness for calculator functions
#include <bits/stdc++.h>
#include "../include/calculator.h"

using namespace std;

// Simple tolerance function for floating point comparisons
bool isClose(double a, double b, double tolerance = 0.001)
{
    return abs(a - b) < tolerance;
}

int main()
{
    cout << "Testing Calculator Functions..." << endl;

    // Square Root Tests
    assert(calculateSquareRoot(4) == 2);
    assert(calculateSquareRoot(9) == 3);
    assert(isClose(calculateSquareRoot(2), 1.414, 0.001));
    assert(isClose(calculateSquareRoot(0.25), 0.5));
    cout << "Square Root: PASS" << endl;

    // Factorial Tests
    assert(calculateFactorial(0) == 1);
    assert(calculateFactorial(5) == 120);
    assert(calculateFactorial(1) == 1);
    cout << "Factorial: PASS" << endl;

    // Natural Log Tests
    assert(isClose(calculateNaturalLog(1), 0));
    assert(isClose(calculateNaturalLog(2.718), 1, 0.01));
    assert(isClose(calculateNaturalLog(10), 2.303, 0.001));
    cout << "Natural Log: PASS" << endl;

    // Power Tests
    assert(calculatePower(2, 3) == 8);
    assert(calculatePower(10, 0) == 1);
    assert(isClose(calculatePower(2.5, 2), 6.25));
    assert(isClose(calculatePower(3, 0.5), 1.732, 0.001));
    assert(calculatePower(-2, 3) == -8);
    cout << "Power: PASS" << endl;

    cout << "ALL TESTS PASSED!" << endl;
    return 0;
}
