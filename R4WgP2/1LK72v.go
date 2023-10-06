package main

import (
	"fmt"
)

// CalculateVolume calculates the volume of a rectangular prism.
func CalculateVolume(length, width, height float64) float64 {
	return length * width * height
}

func main() {
	// Define the dimensions of the rectangular prism
	length := 5.0
	width := 3.0
	height := 2.0

	// Calculate the volume using the function
	volume := CalculateVolume(length, width, height)

	// Print the result
	fmt.Printf("The volume of the rectangular prism with dimensions %.2f x %.2f x %.2f is %.2f cubic units.\n", length, width, height, volume)
}
