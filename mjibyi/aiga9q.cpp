#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the square root using the Newton-Raphson method
double calculateSquareRoot(double number, double epsilon = 1e-6) {
    double guess = number; // Initial guess
    double prevGuess = 0;  // Previous guess

    while (abs(guess - prevGuess) > epsilon) {
        prevGuess = guess;
        guess = 0.5 * (guess + number / guess); // Newton-Raphson formula
    }

    return guess;
}

int main() {
    double number;
    cout << "Enter a number to calculate its square root: ";
    cin >> number;

    if (number < 0) {
        cout << "Square root is not defined for negative numbers." << endl;
    } else {
        double sqrtResult = calculateSquareRoot(number);
        cout << "The square root of " << number << " is approximately " << sqrtResult << endl;
    }

    return 0;
}
