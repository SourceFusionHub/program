#include <iostream>
#include <vector>
using namespace std;

int countSubsetsWithSum(vector<int> &arr, int targetSum)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= targetSum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][targetSum];
}

int main()
{
    vector<int> arr = {2, 4, 6, 8};
    int targetSum = 10;
    int result = countSubsetsWithSum(arr, targetSum);

    cout << "Number of subsets with sum " << targetSum << " is: " << result << endl;

    return 0;
}
