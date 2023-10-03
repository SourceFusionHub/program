fun findLongestSubarrayWithSumDivisibleByK(arr: IntArray, k: Int): Int {
    val prefixSumMap = mutableMapOf<Int, Int>() // Maps remainder to index
    var maxLen = 0
    var currentSum = 0

    prefixSumMap[0] = -1

    for (i in arr.indices) {
        currentSum += arr[i]
        val remainder = (currentSum % k + k) % k // Handle negative remainder

        if (prefixSumMap.containsKey(remainder)) {
            val subarrayLen = i - prefixSumMap[remainder]!!
            if (subarrayLen > maxLen) {
                maxLen = subarrayLen
            }
        } else {
            prefixSumMap[remainder] = i
        }
    }

    return maxLen
}

fun main() {
    val arr = intArrayOf(7, 1, 3, 4, 2, 2)
    val k = 3
    val maxLength = findLongestSubarrayWithSumDivisibleByK(arr, k)
    if (maxLength > 0) {
        println("Longest subarray with sum divisible by $k has length $maxLength")
    } else {
        println("No subarray with sum divisible by $k found.")
    }
}
