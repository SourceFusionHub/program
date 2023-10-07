package main

import (
	"fmt"
)

func main() {
	var base, height float64

	// Prompt the user for input
	fmt.Print("Enter the base of the parallelogram: ")
	fmt.Scan(&base)

	fmt.Print("Enter the height of the parallelogram: ")
	fmt.Scan(&height)

	// Calculate the area of the parallelogram
	area := base * height

	// Display the result
	fmt.Printf("The area of the parallelogram with base %.2f and height %.2f is %.2f square units.\n", base, height, area)
}
