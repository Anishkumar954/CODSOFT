#include <iostream>
using namespace std;

void otheroperation() {
    double num1, num2, result;
    char operation;
    string choice;

    do {
        cout << "\nEnter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;

        switch (operation) {
            case '+':
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Cannot divide by zero!" << endl;
                }
                break;
            default:
                cout << "Invalid operation. Please use +, -, *, or /." << endl;
        }

        cout << "\nDo you want to perform another calculation? (yes/no): ";
        cin >> choice;
    } while (choice == "yes" || choice == "Yes");

    cout << "\nThank you for using My calculator. Goodbye!" << endl;
}

int main() {
    otheroperation();
    return 0;
}