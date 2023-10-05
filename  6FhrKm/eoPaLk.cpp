#include <iostream>

int sum(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + sum(n - 1);
    }
}

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;
    std::cout << "The sum of the first " << n << " natural numbers is " << sum(n) << std::endl;
    return 0;
}