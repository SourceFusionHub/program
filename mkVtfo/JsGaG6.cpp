#include <iostream>
using namespace std;

int main() {
    int num, sum = 0;

    // Input a number from the user
    cout << "Enter a number: ";
    cin >> num;

    // Find the sum of proper divisors
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check if the number is a perfect number
    if (sum == num) {
        cout << num << " is a perfect number." << endl;
    } else {
        cout << num << " is not a perfect number." << endl;
    }

    return 0;
}
