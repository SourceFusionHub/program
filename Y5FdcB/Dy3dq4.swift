func longestPalindromeSubsequence(_ str: String) -> Int {
    let n = str.count
    let characters = Array(str)
    
    var dp = Array(repeating: Array(repeating: 0, count: n), count: n)
    
    for i in 0..<n {
        dp[i][i] = 1
    }
    
    for cl in 2...n {
        for i in 0..<n - cl + 1 {
            let j = i + cl - 1
            if (characters[i] == characters[j] && cl == 2) {
                dp[i][j] = 2
            } else if (characters[i] == characters[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])
            }
        }
    }
    return dp[0][n - 1]
}

let inputString = "bbabcbcab"
let length = longestPalindromeSubsequence(inputString)
print("The length of the longest palindrome subsequence is: \(length)")
