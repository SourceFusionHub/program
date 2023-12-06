fun main() {
    val num1 = 10
    val num2 = 15
    val num3 = 5

    val largest = findLargest(num1, num2, num3)

    println("The largest number among $num1, $num2, and $num3 is $largest")
}

fun findLargest(a: Int, b: Int, c: Int): Int {
    return when {
        a >= b && a >= c -> a
        b >= a && b >= c -> b
        else -> c
    }
}
