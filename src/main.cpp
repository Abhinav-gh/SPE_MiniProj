// main.cpp
// User interface and menu handling

#include "../include/calculator.h"
#include <bits/stdc++.h>

using namespace std;

// Displays the main menu options to the user
void showMenu()
{
    cout << "\n--- C++ Scientific Calculator ---\n";
    cout << "1. Square Root (√x)\n";
    cout << "2. Factorial (!x)\n";
    cout << "3. Natural Logarithm (ln(x))\n";
    cout << "4. Power function (x^b)\n";
    cout << "5. Exit\n";
    cout << "---------------------------------\n";
    cout << "Select an operation: ";
}

int main()
{
    int choice;

    do
    {
        showMenu();
        cin >> choice;

        // Input validation loop
        while (cin.fail())
        {
            cout << "Invalid input. Please enter a number (1-5).\n";
            cin.clear();                                         // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            showMenu();
            cin >> choice;
        }

        switch (choice)
        {
        case 1: // Square Root
        {
            double num;
            cout << "Enter a number: ";
            cin >> num;

            if (cin.fail())
            {
                cout << "Error: Invalid input.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else
            {
                try
                {
                    double result = calculateSquareRoot(num);
                    cout << "Result: The square root of " << num << " is " << result << endl;
                }
                catch (const exception &e)
                {
                    cout << "Error: " << e.what() << endl;
                }
            }
            break;
        }
        case 2: // Factorial
        {
            int num;
            cout << "Enter an integer: ";
            cin >> num;

            if (cin.fail())
            {
                cout << "Error: Invalid input.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else
            {
                try
                {
                    long long result = calculateFactorial(num);
                    cout << "Result: The factorial of " << num << " is " << result << endl;
                }
                catch (const exception &e)
                {
                    cout << "Error: " << e.what() << endl;
                }
            }
            break;
        }
        case 3: // Natural Logarithm
        {
            double num;
            cout << "Enter a number: ";
            cin >> num;

            if (cin.fail())
            {
                cout << "Error: Invalid input.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else
            {
                try
                {
                    double result = calculateNaturalLog(num);
                    cout << "Result: The natural log of " << num << " is " << result << endl;
                }
                catch (const exception &e)
                {
                    cout << "Error: " << e.what() << endl;
                }
            }
            break;
        }
        case 4: // Power Function
        {
            double base, exp;
            cout << "Enter the base: ";
            cin >> base;
            if (cin.fail())
            {
                cout << "Error: Invalid base.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            cout << "Enter the exponent: ";
            cin >> exp;
            if (cin.fail())
            {
                cout << "Error: Invalid exponent.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }

            try
            {
                double result = calculatePower(base, exp);
                cout << "Result: " << base << " raised to the power of " << exp << " is " << result << endl;
            }
            catch (const exception &e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 5:
            cout << "Exiting calculator. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please select a valid operation (1-5).\n";
            break;
        }

    } while (choice != 5);

    return 0;
}