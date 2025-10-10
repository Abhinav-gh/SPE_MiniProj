// Simple test harness for calculator functions
#include <iostream>
#include <cmath>
#include "../include/calculator.h"

using namespace std;

// Simple tolerance function for floating point comparisons
bool isClose(double a, double b, double tolerance = 0.001)
{
    return abs(a - b) < tolerance;
}

// Proper test function 
bool test(const string &testName, bool condition)
{
    if (condition)
    {
        cout << testName << ": PASS" << endl;
        return true;
    }
    else
    {
        cout << testName << ": FAIL" << endl;
        return false;
    }
}

int main()
{
    cout << "Testing Calculator Functions..." << endl;
    int passed = 0, total = 0;

    // Square Root Tests
    total++;
    passed += test("Square Root 4", calculateSquareRoot(4) == 2);
    total++;
    passed += test("Square Root 9", calculateSquareRoot(9) == 3);
    total++;
    passed += test("Square Root 2", isClose(calculateSquareRoot(2), 1.414, 0.001));
    total++;
    passed += test("Square Root 0.25", isClose(calculateSquareRoot(0.25), 0.5));

    // Factorial Tests
    total++;
    passed += test("Factorial 0", calculateFactorial(0) == 1);
    total++;
    passed += test("Factorial 5", calculateFactorial(5) == 120);
    total++;
    passed += test("Factorial 1", calculateFactorial(1) == 1);

    // Natural Log Tests
    total++;
    passed += test("Natural Log 1", isClose(calculateNaturalLog(1), 0));
    total++;
    passed += test("Natural Log e", isClose(calculateNaturalLog(2.718), 1, 0.01));
    total++;
    passed += test("Natural Log 10", isClose(calculateNaturalLog(10), 2.303, 0.001));

    // Power Tests - these will catch the bug!
    double powerResult = calculatePower(2, 3);
    cout << "calculatePower(2, 3) returned: " << powerResult << " (should be 8)" << endl;
    total++;
    passed += test("Power 2^3", calculatePower(2, 3) == 8);
    total++;
    passed += test("Power 10^0", calculatePower(10, 0) == 1);
    total++;
    passed += test("Power 2.5^2", isClose(calculatePower(2.5, 2), 6.25));
    total++;
    passed += test("Power 3^0.5", isClose(calculatePower(3, 0.5), 1.732, 0.001));
    total++;
    passed += test("Power (-2)^3", calculatePower(-2, 3) == -8);

    cout << "\nResults: " << passed << "/" << total << " tests passed" << endl;
    if (passed == total)
    {
        cout << "ALL TESTS PASSED!" << endl;
        return 0;
    }
    else
    {
        cout << "SOME TESTS FAILED!" << endl;
        return 1;
    }
}
