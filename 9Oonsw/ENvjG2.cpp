#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    int sum = (n * (n + 1) * (2 * n + 1)) / 6;

    cout << "The sum of the series 1^2 + 2^2 + 3^2 + ... + n^2 is: " << sum << endl;

    return 0;
}
