package main

import "fmt"

// Function to check if a number is prime
func isPrime(n int) bool {
    if n <= 1 {
        return false
    }
    if n <= 3 {
        return true
    }
    if n%2 == 0 || n%3 == 0 {
        return false
    }

    i := 5
    for i*i <= n {
        if n%i == 0 || n%(i+2) == 0 {
            return false
        }
        i += 6
    }
    return true
}

func main() {
    var limit int
    fmt.Print("Enter a limit: ")
    fmt.Scan(&limit)

    sum := 0
    for i := 2; i <= limit; i++ {
        if isPrime(i) {
            sum += i
        }
    }

    fmt.Printf("The sum of prime numbers up to %d is: %d\n", limit, sum)
}
