#include <stdio.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the longest palindromic subsequence
int longestPalindromicSubsequence(char* str) {
    int n = strlen(str);
    int dp[n][n];

    // Initialize the dp table
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;  // Each individual character is a palindrome of length 1
    }

    // Fill the dp table
    for (int cl = 2; cl <= n; cl++) {
        for (int i = 0; i < n - cl + 1; i++) {
            int j = i + cl - 1;
            if (str[i] == str[j] && cl == 2) {
                dp[i][j] = 2;
            } else if (str[i] == str[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    // The length of the longest palindromic subsequence is stored in dp[0][n-1]
    return dp[0][n - 1];
}

int main() {
    char str[] = "BBABCBCAB";
    int length = longestPalindromicSubsequence(str);
    printf("The length of the longest palindromic subsequence is: %d\n", length);
    return 0;
}
