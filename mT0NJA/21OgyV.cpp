#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    double a = 0.5, r = 0.5;
    double ans = 0.0;
    
    cout << "Enter the value of n (number of terms)" << endl;
    cin >> n;

    if(n<0) {
        cout << "Invalid input" << endl;
        return 0;
    } 

    ans = a*(1-pow(r, n))/(1-r);
    cout << ans << endl; 
}