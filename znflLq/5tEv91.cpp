#include <iostream>
#include <unordered_set>

// Function to calculate the sum of the squares of digits of a number
int sumOfSquaresOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

// Function to check if a number is a happy number
bool isHappy(int n) {
    std::unordered_set<int> seen;
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = sumOfSquaresOfDigits(n);
    }
    return n == 1;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (isHappy(num)) {
        std::cout << num << " is a happy number." << std::endl;
    } else {
        std::cout << num << " is not a happy number." << std::endl;
    }

    return 0;
}
