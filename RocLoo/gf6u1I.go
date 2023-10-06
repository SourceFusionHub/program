package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Print("Enter a number: ")
	fmt.Scanln(&n)

	if isHappy(n) {
		fmt.Println(n, "is a happy number")
	} else {
		fmt.Println(n, "is not a happy number")
	}
}

func isHappy(n int) bool {
	seen := make(map[int]bool)

	for n != 1 {
		sum := 0
		for _, r := range strconv.Itoa(n) {
			digit := int(r - '0')
			sum += digit * digit
		}
		n = sum

		if seen[n] {
			return false
		}
		seen[n] = true
	}

	return true
}
