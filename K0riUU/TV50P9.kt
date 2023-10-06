fun maxSumSubarrayWithK4s(arr: IntArray, k: Int): Int {
    var left = 0
    var maxSum = 0
    var maxCount = 0
    var currentCount = 0
    var currentSum = 0

    for (right in arr.indices) {
        if (arr[right] == 4) {
            currentCount++
        }

        currentSum += arr[right]

        while (currentCount > k) {
            if (arr[left] == 4) {
                currentCount--
            }
            currentSum -= arr[left]
            left++
        }

        if (currentSum > maxSum) {
            maxSum = currentSum
            maxCount = currentCount
        }
    }

    return maxSum
}

fun main() {
    val arr = intArrayOf(1, 2, 3, 4, 4, 1, 4, 1, 4, 5)
    val k = 2

    val result = maxSumSubarrayWithK4s(arr, k)
    println("Maximum sum subarray with at most $k fours: $result")
}
