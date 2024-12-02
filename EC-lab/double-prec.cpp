#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototype for strToDbl, this will be called during the extract numeric function
double strToDbl(const string& str);

// Function to extract and validate numeric value from the input string
double extractNumeric(const string& userString) {   //
    // handles errors for empty string returns invalid string number per instructions 
    if (userString.empty()) {
        return -999999.99;
    }

    int len = userString.length();
    int decimalCount = 0;

    for (int i = 0; i < len; ++i) {
        char current = userString[i];

        // Check for sign characters
        if (current == '+' || current == '-') {
            if (i != 0) {
                return -999999.99; // it is an invalid num if the sign is not at the begining
            }
            // invalid if it contains just one sign
            if (len == 1) {
                return -999999.99;
            }
            continue;
        }

        // Check for decimal point
        if (current == '.') {
            decimalCount++;
            if (decimalCount > 1) {
                return -999999.99; // More than one decimal point
            }
            // Ensure there's at least one digit before or after the decimal
            if ((i == 0 || !(userString[i - 1] >= '0' && userString[i - 1] <= '9')) &&
                (i == len - 1 || !(userString[i + 1] >= '0' && userString[i + 1] <= '9'))) {
                return -999999.99;
            }
            continue;
        }

        // Check for digits
        if (!(current >= '0' && current <= '9')) {
            return -999999.99; // Invalid character found
        }
    }

    // call strToDbl function
    double num = strToDbl(userString);
    return num;
}

// Function to convert string to double without using std::stod
double strToDbl(const string& str) {
    double result = 0.0;   // initializing the variables
    int i = 0;
    bool negative = false;

    // Handle sign
    if (str[i] == '-') {
        negative = true;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // handle digits before the decimal
    while (i < str.length() && (str[i] >= '0' && str[i] <= '9')) {
        result = result * 10.0 + (str[i] - '0');
        i++;
    }

    // handle digits after the decimal
    if (i < str.length() && str[i] == '.') {
        i++;
        double fraction = 0.1;
        while (i < str.length() && (str[i] >= '0' && str[i] <= '9')) {
            result += (str[i] - '0') * fraction;
            fraction *= 0.1;
            i++;
        }
    }

    return negative ? -result : result;
}

int main() {
    while (true) {
        string userString;

        // Prompts the user for input
        cout << "----------------------------------------" << endl;
        cout << "Enter a string below (or 'END' to quit): ";
        cin >> userString;

        // Check for termination condition
        if (userString == "END") {
            break;
        }

        // handles input error
        if (userString.length() > 20) {
            cout << "Enter a valid string of 20 or fewer characters!" << endl << endl;
            continue;
        }

        // creates num as double and call extract numeric function 
        double num = extractNumeric(userString);

        // Display output based on extraction result
        if (num != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << num << endl << endl;
        } else {
            cout << "The input is invalid." << endl << endl;
        }
    }

    return 0;
}
