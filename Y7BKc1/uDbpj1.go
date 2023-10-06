package main

import (
	"fmt"
	"math"
)

func calculateHexagonArea(side float64) float64 {
	area := (3 * math.Sqrt(3) * math.Pow(side, 2)) / 2
	return area
}

func main() {
	var side float64

	fmt.Print("Enter the side length of the hexagon: ")
	fmt.Scan(&side)

	if side <= 0 {
		fmt.Println("Side length must be a positive number.")
		return
	}

	area := calculateHexagonArea(side)
	fmt.Printf("The area of the hexagon is %.2f square units.\n", area)
}
