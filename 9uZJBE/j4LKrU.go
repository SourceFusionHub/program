package main

import (
	"fmt"
	"math"
	"strconv"
)

// Function to calculate the sum of digits in a number
func digitSum(n int) int {
	sum := 0
	for n > 0 {
		sum += n % 10
		n /= 10
	}
	return sum
}

// Function to calculate the sum of digits in the prime factorization of a number
func primeFactorizationDigitSum(n int) int {
	sum := 0
	for i := 2; i <= n; i++ {
		for n%i == 0 {
			sum += digitSum(i)
			n /= i
		}
	}
	return sum
}

// Function to check if a number is a Smith number
func isSmithNumber(n int) bool {
	return digitSum(n) == primeFactorizationDigitSum(n)
}

func main() {
	// Test the function
	number := 378
	if isSmithNumber(number) {
		fmt.Printf("%d is a Smith number.\n", number)
	} else {
		fmt.Printf("%d is not a Smith number.\n", number)
	}
}
