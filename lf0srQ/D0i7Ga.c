#include <stdio.h>

#define maxLen 10

// Variables to store states of dp
int dp[maxLen];

// Variable to check if a given state has been solved
int v[maxLen];

// Function to find the maximum sum subsequence
// such that no two elements are adjacent
int maxSum(int arr[], int i, int n)
{
    // Base case
    if (i >= n)
        return 0;

    // To check if a state has been solved
    if (v[i])
        return dp[i];
    v[i] = 1;

    // Required recurrence relation
    dp[i] = arr[i] + maxSum(arr, i + 2, n);
    int withoutCurrent = maxSum(arr, i + 1, n);

    if (dp[i] < withoutCurrent) {
        dp[i] = withoutCurrent;
    }

    // Returning the value
    return dp[i];
}

// Driver code
int main()
{
    int arr[] = { 12, 9, 7, 33 };
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < maxLen; i++) {
        v[i] = 0;
    }

    printf("%d\n", maxSum(arr, 0, n));

    return 0;
}
