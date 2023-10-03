fun findLongestIncreasingSubsequence(arr: Array<IntArray>): Int {
    val n = arr.size
    val m = arr[0].size
    // dp[i][j] stores the length of the longest increasing subsequence
    // ending at arr[i][j]
    val dp = Array(n) { IntArray(m) }
    // Initialize the dp table
    for (i in 0 until n) {
        for (j in 0 until m) {
            dp[i][j] = 1
        }
    }

    for (i in 1 until n) {
        for (j in 1 until m) {
            if (arr[i][j] > arr[i - 1][j]) {
                dp[i][j] = maxOf(dp[i][j], dp[i - 1][j] + 1)
            }
        }
    }

    for (j in 1 until m) {
        for (i in 1 until n) {
            if (arr[i][j] > arr[i][j - 1]) {
                dp[i][j] = maxOf(dp[i][j], dp[i][j - 1] + 1)
            }
        }
    }

    var maxLen = 0
    for (i in 0 until n) {
        for (j in 0 until m) {
            maxLen = maxOf(maxLen, dp[i][j])
        }
    }
    return maxLen
}
