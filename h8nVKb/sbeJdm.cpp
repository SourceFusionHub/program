#include <iostream>
#include <vector>

using namespace std;

// Function to find the number of ways to partition n into positive integers
int partitionCount(int n)
{
    vector<int> dp(n + 1, 0);

    // There is one way to partition 0 (empty partition)
    dp[0] = 1;

    // Calculate the number of ways to partition for each value from 1 to n
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] += dp[j - i];
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int ways = partitionCount(n);
    cout << "Number of ways to partition " << n << " into positive integers: " << ways << endl;

    return 0;
}
