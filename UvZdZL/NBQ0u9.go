package main

import (
	"fmt"
	"math"
)

func cylinderVolume(radius float64, height float64) float64 {
	volume := math.Pi * math.Pow(radius, 2) * height
	return volume
}

func main() {
	radius := 5.0
	height := 10.0

	volume := cylinderVolume(radius, height)
	fmt.Printf("The volume of the cylinder with radius %.2f and height %.2f is %.2f\n", radius, height, volume)
}
