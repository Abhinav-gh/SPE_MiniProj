// Simple test harness for calculator functions
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include "../include/calculator.h"

using namespace std;

// Global vector to track failed tests with details
vector<string> failedTests;

// Simple tolerance function for floating point comparisons
bool isClose(double a, double b, double tolerance = 0.001)
{
    return abs(a - b) < tolerance;
}

// Test function for exact values
template <typename T>
bool test(const string &testName, T actual, T expected)
{
    if (actual == expected)
    {
        cout << testName << ": PASS" << endl;
        return true;
    }
    else
    {
        cout << testName << ": FAIL" << endl;
        stringstream ss;
        ss << testName << " (got: " << actual << ", expected: " << expected << ")";
        failedTests.push_back(ss.str());
        return false;
    }
}

// Test function for floating point with tolerance
bool testClose(const string &testName, double actual, double expected, double tolerance = 0.001)
{
    if (isClose(actual, expected, tolerance))
    {
        cout << testName << ": PASS" << endl;
        return true;
    }
    else
    {
        cout << testName << ": FAIL" << endl;
        stringstream ss;
        ss << testName << " (got: " << actual << ", expected: " << expected << ", tolerance: " << tolerance << ")";
        failedTests.push_back(ss.str());
        return false;
    }
}

// Generic test function for boolean conditions (fallback)
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
        failedTests.push_back(testName + " (condition failed)");
        return false;
    }
}

int main()
{
    cout << "Testing Calculator Functions..." << endl;
    int passed = 0, total = 0;

    // Square Root Tests
    total++;
    passed += test("Square Root 4", calculateSquareRoot(4), 2.0);
    total++;
    passed += test("Square Root 9", calculateSquareRoot(9), 3.0);
    total++;
    passed += testClose("Square Root 2", calculateSquareRoot(2), 1.414, 0.001);
    total++;
    passed += testClose("Square Root 0.25", calculateSquareRoot(0.25), 0.5);

    // Factorial Tests
    total++;
    passed += test("Factorial 0", calculateFactorial(0), 1LL);
    total++;
    passed += test("Factorial 5", calculateFactorial(5), 120LL);
    total++;
    passed += test("Factorial 1", calculateFactorial(1), 1LL);

    // Natural Log Tests
    total++;
    passed += testClose("Natural Log 1", calculateNaturalLog(1), 0.0);
    total++;
    passed += testClose("Natural Log e", calculateNaturalLog(2.718), 1.0, 0.01);
    total++;
    passed += testClose("Natural Log 10", calculateNaturalLog(10), 2.303, 0.001);

    // Power Tests
    total++;
    passed += test("Power 2^3", calculatePower(2, 3), 8.0);
    total++;
    passed += test("Power 10^0", calculatePower(10, 0), 1.0);
    total++;
    passed += testClose("Power 2.5^2", calculatePower(2.5, 2), 6.25);
    total++;
    passed += testClose("Power 3^0.5", calculatePower(3, 0.5), 1.732, 0.001);
    total++;
    passed += test("Power (-2)^3", calculatePower(-2, 3), -8.0);

    cout << "\nResults: " << passed << "/" << total << " tests passed" << endl;

    if (passed == total)
    {
        cout << "ALL TESTS PASSED!" << endl;
        return 0;
    }
    else
    {
        cout << "\nFAILED TESTS:" << endl;
        for (const string &test : failedTests)
        {
            cout << "- " << test << endl;
        }
        cout << "\nSOME TESTS FAILED!" << endl;
        return 1;
    }
}
