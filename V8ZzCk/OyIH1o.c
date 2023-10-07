#include <stdio.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the Longest Common Subsequence for strings
void findLCS(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    
    int dp[m + 1][n + 1];

    // Build the dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Length of LCS is dp[m][n]
    int lcs_length = dp[m][n];

    // Now, let's find the LCS itself
    char lcs[lcs_length + 1];
    lcs[lcs_length] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[lcs_length - 1] = str1[i - 1];
            i--;
            j--;
            lcs_length--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the LCS
    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char str1[] = "AGGTAB";
    char str2[] = "GXTXAYB";

    findLCS(str1, str2);

    return 0;
}
