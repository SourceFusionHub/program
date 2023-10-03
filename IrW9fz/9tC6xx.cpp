#include<bits/stdc++.h>

using namespace std; 

// Implementing a function that returns the sum of 1 + 1/2 + 1/3 + ... + 1/n

double sum(int n){
    double ans = 0;
    for(int i=1;i<=n;i++){
        ans += (1.0/i);
    }
    return ans;
}


int main(){

    int n;
    cin>>n;

    cout<<sum(n)<<endl;

    return 0;
}