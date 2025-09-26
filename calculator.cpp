// calculator.cpp

#include "calculator.h"
#include <iostream>
#include <cmath>
#include <limits>

using namespace std; // Using the standard namespace

// Displays the main menu options to the user
void showMenu() {
    cout << "\n--- C++ Scientific Calculator ---\n";
    cout << "1. Square Root (vx)\n";
    cout << "2. Factorial (!x)\n";
    cout << "3. Natural Logarithm (ln(x))\n";
    cout << "4. Power function (x^b)\n";
    cout << "5. Exit\n";
    cout << "---------------------------------\n";
    cout << "Select an operation: ";
}

// Handles Square Root
void performSquareRoot() {
    double num;
    cout << "Enter a number: ";
    cin >> num;

    if (cin.fail() || num < 0) {
        cout << "Error: Invalid input. Please enter a non-negative number.\n";
    } else {
        cout << "Result: The square root of " << num << " is " << sqrt(num) << endl;
    }
}

// Handles Factorial
void performFactorial() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    if (cin.fail() || num < 0) {
        cout << "Error: Invalid input. Factorial is not defined for negative numbers.\n";
    } else {
        long long result = 1;
        for (int i = 1; i <= num; ++i) {
            result *= i;
        }
        cout << "Result: The factorial of " << num << " is " << result << endl;
    }
}

// Handles Natural Logarithm
void performNaturalLog() {
    double num;
    cout << "Enter a number: ";
    cin >> num;

    if (cin.fail() || num <= 0) {
        cout << "Error: Invalid input. Logarithm is only defined for positive numbers.\n";
    } else {
        cout << "Result: The natural log of " << num << " is " << log(num) << endl;
    }
}

// Handles Power Function
void performPower() {
    double base, exp;
    cout << "Enter the base: ";
    cin >> base;
    if (cin.fail()) {
        cout << "Error: Invalid base.\n";
        return;
    }
    cout << "Enter the exponent: ";
    cin >> exp;
     if (cin.fail()) {
        cout << "Error: Invalid exponent.\n";
        return;
    }
    cout << "Result: " << base << " raised to the power of " << exp << " is " << pow(base, exp) << endl;
}
