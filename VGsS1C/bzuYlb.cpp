#include <iostream>
#include <set>

using namespace std;

// Function checking if a number is happy
bool isHappy(int n) {
    set<int> temp;
    while (n != 1 && temp.find(n) == temp.end()) 
    {
        int next = 0;
        temp.insert(n);
        while (n > 0) 
        {
            int digit = n % 10;
            next += digit * digit;
            n /= 10;
        }
        n = next;
    }
    return n == 1;
}

// Function checking if a number is prime
bool isPrime(int n) {
    if (n <= 3) 
        return true;

    if (n <= 1) 
        return false;

    if (n % 2 == 0 || n % 3 == 0) 
        return false;
    
    for (int i = 5; i * i <= n; i += 6) 
    {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    
    return true;
}

// Function to check if a number is a happy prime
bool isHappyPrime(int n) 
{
    return isPrime(n) && isHappy(n);
}

int main() 
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isHappyPrime(n)) 
    {
        cout << n << " is a happy prime number." << endl;
    } else 
    {
        cout <<"Oops "<< n << " is not a happy prime number." << endl;
    }

    return 0;
}
