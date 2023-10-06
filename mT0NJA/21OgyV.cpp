#include<iostream>
#include<cmath>

int main() {
    int n;
    double a = 0.5, r = 0.5;
    double ans = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    if(n<0) {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }

    ans = a*(1-pow(r, n))/(1-r);
    std::cout << "Sum of geometric progression: " << ans << std::endl;
}