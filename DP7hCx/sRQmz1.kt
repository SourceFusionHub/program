fun findLongestIncreasingSubarray(arr: IntArray): IntArray {
    var maxLength = 1
    var currentLength = 1
    var endIndex = 0
    var currentEndIndex = 0

    for (i in 1 until arr.size) {
        if (arr[i] > arr[i - 1]) {
            currentLength++
            currentEndIndex = i
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength
                endIndex = currentEndIndex
            }
            currentLength = 1
        }
    }

    // Handle the case where the longest increasing subarray ends at the last element
    if (currentLength > maxLength) {
        maxLength = currentLength
        endIndex = currentEndIndex
    }

    val startIndex = endIndex - maxLength + 1
    val result = IntArray(maxLength) { arr[startIndex + it] }
    return result
}

fun main() {
    val arr = intArrayOf(1, 2, 3, 1, 2, 3, 4, 5, 6)
    val longestIncreasingSubarray = findLongestIncreasingSubarray(arr)
    println("Longest Increasing Subarray: ${longestIncreasingSubarray.joinToString(", ")}")
}
