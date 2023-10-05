fun main() {
    val number = 12345
    val reversedNumber = findReverse(number)
    println("Reversed Number: $reversedNumber")
}

fun findReverse(number: Int): Int {
    var reversedNumber = 0
    var tempNumber = number

    while (tempNumber != 0) {
        val remainder = tempNumber % 10
        reversedNumber = reversedNumber * 10 + remainder
        tempNumber /= 10
    }

    return reversedNumber
}
