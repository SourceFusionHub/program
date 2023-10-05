package main

import (
    "fmt"
    "math"
)

func calculateConeVolume(radius float64, height float64) float64 {
    // Calculate the volume using the formula
    volume := (1.0 / 3.0) * math.Pi * math.Pow(radius, 2) * height
    return volume
}

func main() {
    // Example usage:
    radius := 3.0
    height := 4.0
    volume := calculateConeVolume(radius, height)
    fmt.Printf("The volume of the cone with radius %.2f and height %.2f is %.2f\n", radius, height, volume)
}
