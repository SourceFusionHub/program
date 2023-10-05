import java.util.*

fun findKthLargest(nums: IntArray, k: Int): Int {
    val priorityQueue = PriorityQueue<Int>()

    for (num in nums) {
        priorityQueue.offer(num)
        if (priorityQueue.size > k) {
            priorityQueue.poll()
        }
    }

    return priorityQueue.peek()
}

fun main() {
    val nums = intArrayOf(3, 2, 1, 5, 6, 4)
    val k = 2

    val result = findKthLargest(nums, k)
    println("The $k-th largest element in the array is $result")
}
