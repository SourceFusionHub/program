#include <iostream>
using namespace std;

const int MAX_DIGIT = 50; // Maximum number of digits
int factorial[MAX_DIGIT];


void computeFactorials() {
    factorial[0] = 1;
    for (int i = 1; i < MAX_DIGIT; ++i) {
        factorial[i] = factorial[i - 1] * i;
    }
}


bool isStrongNumber(int num) {
    int originalNum = num;
    int sum = 0;
    
    while (num > 0) {
        int digit = num % 10;
        sum += factorial[digit];
        num /= 10;
    }
    
    return sum == originalNum;
}

int main() {
    computeFactorials(); 
    
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    if (isStrongNumber(num)) {
        cout << num << " is a strong number." << endl;
    } else {
        cout << num << " is not a strong number." << endl;
    }
    
    return 0;
}
