// main.cpp

#include "calculator.h"
#include <iostream>
#include <limits>

using namespace std; // Using the standard namespace

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        // Input validation loop
        while (cin.fail()) {
            cout << "Invalid input. Please enter a number (1-5).\n";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            showMenu();
            cin >> choice;
        }

        switch (choice) {
            case 1:
                performSquareRoot();
                break;
            case 2:
                performFactorial();
                break;
            case 3:
                performNaturalLog();
                break;
            case 4:
                performPower();
                break;
            case 5:
                cout << "Exiting calculator. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid operation (1-5).\n";
                break;
        }
         // Clear remaining input from the buffer before the next loop iteration
        if (choice != 5) {
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (choice != 5);

    return 0;
}
