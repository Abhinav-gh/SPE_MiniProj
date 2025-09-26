// calculator.h

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdexcept>

// Displays the user menu
void showMenu();

// Performs square root operation: v(x)
void performSquareRoot();

// Performs factorial operation: !x
void performFactorial();

// Performs natural logarithm operation: ln(x)
void performNaturalLog();

// Performs power operation: x^b
void performPower();

// Testable calculator functions (for unit testing)
double calculateSquareRoot(double num);
long long calculateFactorial(int num);
double calculateNaturalLog(double num);
double calculatePower(double base, double exponent);

#endif // CALCULATOR_H
