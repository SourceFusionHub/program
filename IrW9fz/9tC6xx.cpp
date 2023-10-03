#include<bits/stdc++.h>

#define ll long long int
#define ld long double
#define ff(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair

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