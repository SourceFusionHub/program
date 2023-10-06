#include <iostream>
#include <vector>
using namespace std;
int countPartitions(int n){
    vector<int>dp(n+1,0);
    dp[0]=1;
    for (int i=1;i<=n;++i){
        for (int j=i;j<=n;++j){
            dp[j]+=dp[j-i];
        }
    }

    return dp[n];
}
int main(){
    int n;
    cout<<"Enter a positive integer: ";
    cin>>n;
    int ways=countPartitions(n);
    cout<<"Number of ways to partition " << n << " into positive integers: " << ways<<endl;
    return 0;
}
