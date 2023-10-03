#include <iostream>

// Function to find the GCD (Greatest Common Divisor)
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the LCM (Least Common Multiple) 
int findLCM(int a, int b) {
    int gcd = findGCD(a, b);
    int lcm = (a * b) / gcd;
    return lcm;
}

int main() {
    int num1, num2;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    int gcd = findGCD(num1, num2);
    int lcm = findLCM(num1, num2);

    std::cout << "GCD of " << num1 << " and " << num2 << " is " << gcd << std::endl;
    std::cout << "LCM of " << num1 << " and " << num2 << " is " << lcm << std::endl;

    return 0;
}
