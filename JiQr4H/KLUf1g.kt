fun findMaximumSumRectangle(matrix: Array<Array<Int>>): Int {
    val rows = matrix.size
    val cols = matrix[0].size

    var maxSum = Int.MIN_VALUE
    var leftBound = 0
    var rightBound = 0
    var topBound = 0
    var bottomBound = 0

    for (left in 0 until cols) {
        val temp = IntArray(rows)
        for (right in left until cols) {
            for (row in 0 until rows) {
                temp[row] += matrix[row][right]
            }

            val (currentSum, currentTop, currentBottom) = kadane(temp)
            if (currentSum > maxSum) {
                maxSum = currentSum
                leftBound = left
                rightBound = right
                topBound = currentTop
                bottomBound = currentBottom
            }
        }
    }

    println("Maximum Sum: $maxSum")
    println("Coordinates:")
    println("Top-Left: ($topBound, $leftBound)")
    println("Bottom-Right: ($bottomBound, $rightBound)")

    return maxSum
}

fun kadane(arr: IntArray): Triple<Int, Int, Int> {
    var maxSum = Int.MIN_VALUE
    var currentSum = 0
    var start = 0
    var currentStart = 0
    var end = 0

    for (i in arr.indices) {
        currentSum += arr[i]

        if (currentSum > maxSum) {
            maxSum = currentSum
            start = currentStart
            end = i
        }

        if (currentSum < 0) {
            currentSum = 0
            currentStart = i + 1
        }
    }

    return Triple(maxSum, start, end)
}

fun main() {
    val matrix = arrayOf(
        arrayOf(1, 2, -1, -4, -20),
        arrayOf(-8, -3, 4, 2, 1),
        arrayOf(3, 8, 10, 1, 3),
        arrayOf(-4, -1, 1, 7, -6)
    )

    val maxSum = findMaximumSumRectangle(matrix)
}
