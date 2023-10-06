#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

void findLongestPalindromicSubstring(char *input) {
    int inputLength = strlen(input);

    // Create a modified string with '#' inserted between each character and at the beginning and end.
    int modifiedLength = 2 * inputLength + 1;
    char modifiedString[modifiedLength];
    for (int i = 0, j = 0; i < modifiedLength; i++) {
        modifiedString[i] = (i % 2 == 0) ? '#' : input[j++];
    }

    int P[modifiedLength]; // Array to store the palindrome lengths
    int C = 0; // Center of the rightmost palindrome
    int R = 0; // Right boundary of the rightmost palindrome

    for (int i = 0; i < modifiedLength; i++) {
        int mirror = 2 * C - i; // Mirror of the current index i

        // Check if the current index i is within the rightmost palindrome's boundary
        if (i < R) {
            P[i] = min(R - i, P[mirror]);
        }

        // Expand the palindrome centered at i
        int a = i + (1 + P[i]);
        int b = i - (1 + P[i]);
        while (a < modifiedLength && b >= 0 && modifiedString[a] == modifiedString[b]) {
            P[i]++;
            a++;
            b--;
        }

        // If the palindrome centered at i expands beyond R, adjust C and R
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // Find the maximum palindrome length and its center
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 0; i < modifiedLength; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Extract the longest palindromic substring from the modified string
    int start = (centerIndex - maxLen) / 2;
    int end = start + maxLen;
    printf("Longest Palindromic Substring: ");
    for (int i = start; i < end; i++) {
        printf("%c", input[i]);
    }
    printf("\n");
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    findLongestPalindromicSubstring(input);
    return 0;
}
