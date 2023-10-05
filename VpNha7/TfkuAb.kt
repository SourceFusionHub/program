fun generatePrimesInRange(n: Int): List<Int> {
    // Create a boolean array "isPrime" and initialize all entries it as true.
    // A value in isPrime[i] will finally be false if i is not a prime, else true.
    val isPrime = BooleanArray(n + 1) { true }

    // Initialize the first two numbers (0 and 1) as not prime.
    isPrime[0] = false
    isPrime[1] = false

    // Mark all multiples of each prime number as not prime.
    for (p in 2..Math.sqrt(n.toDouble()).toInt()) {
        if (isPrime[p]) {
            for (i in p * p..n step p) {
                isPrime[i] = false
            }
        }
    }

    // Collect all prime numbers into a list.
    val primes = mutableListOf<Int>()
    for (i in 2..n) {
        if (isPrime[i]) {
            primes.add(i)
        }
    }

    return primes
}

fun main() {
    val range = 100 // Change this to the desired range
    val primeNumbers = generatePrimesInRange(range)
    println("Prime numbers within the range 2 to $range:")
    println(primeNumbers.joinToString(", "))
}
