fun maxSumSubarrayWithKEvens(arr: IntArray, k: Int): Pair<Int, Int> {
    var left = 0
    var evenCount = 0
    var maxSum = 0
    var maxLeft = 0
    var maxRight = 0

    for (right in arr.indices) {
        if (arr[right] % 2 == 0) {
            evenCount++
        }

        while (evenCount > k) {
            if (arr[left] % 2 == 0) {
                evenCount--
            }
            left++
        }

        val currentSum = arr.sliceArray(left..right).sum()

        if (currentSum > maxSum) {
            maxSum = currentSum
            maxLeft = left
            maxRight = right
        }
    }

    return Pair(maxLeft, maxRight)
}

fun main() {
    val arr = intArrayOf(1, 2, 3, 4, 6, 8, 10, 12, 14)
    val k = 2

    val result = maxSumSubarrayWithKEvens(arr, k)

    println("Maximum sum subarray with at most $k even integers:")
    for (i in result.first..result.second) {
        print("${arr[i]} ")
    }
    println("\nSum: ${arr.sliceArray(result.first..result.second).sum()}")
}
