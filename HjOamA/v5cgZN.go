package main

import (
	"fmt"
)

func parallelogramArea(base, height float64) float64 {
	return base * height
}

func main() {
	var base, height float64

	// Get user input for base and height
	fmt.Print("Enter the base of the parallelogram: ")
	fmt.Scan(&base)

	fmt.Print("Enter the height of the parallelogram: ")
	fmt.Scan(&height)

	// Calculate the area
	area := parallelogramArea(base, height)

	// Display the result
	fmt.Printf("The area of the parallelogram with base %.2f and height %.2f is %.2f\n", base, height, area)
}
