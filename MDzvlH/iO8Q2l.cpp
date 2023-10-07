#include<bits/stdc++.h>
using namespace std;

int longcommSubstr(string s1,string s2)
{
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=0;
                }
                
                ans = max(ans,dp[i][j]);
            }
        }
        
        return ans;
}

int main()
{
    string s1,s2;

    cout<<"Enter 2 Strings: \n";
    cin>>s1;
    cin>>s2;

    cout<<"\nThe Length of longest common substring: "<<longcommSubstr(s1,s2);

    return 0;
}