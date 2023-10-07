def longest_palindromic_subsequence(string):
    n = len(string)

    dp = [[0] * n for _ in range(n)]

    for i in range(n):
        dp[i][i] = 1

    for cl in range(2, n + 1):
        for i in range(n - cl + 1):
            j = i + cl - 1
            if string[i] == string[j] and cl == 2:
                dp[i][j] = 2
            elif string[i] == string[j]:
                dp[i][j] = dp[i + 1][j - 1] + 2
            else:
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])

    lps_length = dp[0][n - 1]
    lps = [''] * lps_length
    i, j = 0, n - 1
    while i < j:
        if string[i] == string[j]:
            lps[lps_length - 1] = string[i]
            lps_length -= 1
            i += 1
            j -= 1
        elif dp[i][j - 1] > dp[i + 1][j]:
            j -= 1
        else:
            i += 1

    return ''.join(lps)

input_string = "bbbab"
result = longest_palindromic_subsequence(input_string)
print(f"Longest Palindromic Subsequence in '{input_string}': {result}")