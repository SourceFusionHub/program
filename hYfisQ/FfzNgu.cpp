// #include <bits/stdc++.h>
// using namespace std;


//function to determine palindrome or not(base 16) 
int Palindrome(int n)
{
    int rev = 0;
    int n1 = n;
    while (n1) {
        rev = rev*16+n1%16;
        n1=n1/16;
    }
    return n==rev;
}
//example use case



// int main(){
//     (Palindrome(17))? (cout<<"palindrome"): (cout<<"not a Palindrome");
//     return 0;
// }