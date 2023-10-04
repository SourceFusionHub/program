fun main() {
    val inputString = "Hello, World!"
    val reversedString = reverseString(inputString)
    println("Original String: $inputString")
    println("Reversed String: $reversedString")
}

fun reverseString(input: String): String {
    return input.reversed()
}
