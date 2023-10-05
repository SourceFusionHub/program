fun fibonacci(n: Int): Long {
    if (n <= 1) {
        return n.toLong()
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2)
    }
}
