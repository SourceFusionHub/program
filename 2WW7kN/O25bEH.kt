//Calculated the product of two floating-point numbers in Kotlin with user input for both the numbers
fun main() {
    print("Enter the first number: ")
    val num1 = readLine()!!.toDouble()
    print("Enter the second number: ")
    val num2 = readLine()!!.toDouble()
    val product = num1 * num2
    println("The product of $num1 and $num2 is $product")
}
