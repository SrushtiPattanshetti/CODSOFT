#include <iostream>
#include <limits>

using namespace std;

bool validInput() {
    if (cin.fail()) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input
        return false;
    }
    return true;
}

int main() {
    double num1, num2;
    char operation;
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
        cout << "Enter first number: ";
        cin >> num1;
        if (!validInput()) {
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        cout << "Enter second number: ";
        cin >> num2;
        if (!validInput()) {
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;

        switch (operation) {
            case '+':
                cout << "Result: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Result: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << num1 / num2 << endl;
                } else {
                    cout << "Cannot divide by zero!" << endl;
                }
                break;
            default:
                cout << "Invalid operation!" << endl;
        }

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> cont;
    }

    cout << "Calculator closed." << endl;

    return 0;
}