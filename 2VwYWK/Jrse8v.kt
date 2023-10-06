fun findSecondLargestElement(arr: IntArray): Int {
    var firstLargest = Int.MIN_VALUE
    var secondLargest = Int.MIN_VALUE

    for (num in arr) {
        if (num > firstLargest) {
            secondLargest = firstLargest
            firstLargest = num
        } else if (num > secondLargest && num != firstLargest) {
            secondLargest = num
        }
    }

    return secondLargest
}

fun main() {
    val numbers = intArrayOf(10, 5, 8, 20, 2, 18)
    val secondLargest = findSecondLargestElement(numbers)
    println("Second largest element in the array: $secondLargest")
}
