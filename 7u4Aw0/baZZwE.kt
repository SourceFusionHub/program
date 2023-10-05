fun isHappyNumber(n: Int): Boolean {
    var num = n
    val seen = HashSet<Int>()

    while (num != 1 && !seen.contains(num)) {
        seen.add(num)
        num = getNextNumber(num)
    }

    return num == 1
}

fun getNextNumber(n: Int): Int {
    var sum = 0
    var num = n

    while (num > 0) {
        val digit = num % 10
        sum += digit * digit
        num /= 10
    }

    return sum
}

fun main() {
    println("Enter a number:")
    val number = readLine()?.toIntOrNull()

    if (number != null) {
        if (isHappyNumber(number)) {
            println("$number is a happy number.")
        } else {
            println("$number is not a happy number.")
        }
    } else {
        println("Invalid input. Please enter a valid number.")
    }
}
