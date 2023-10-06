package main

import (
    "fmt"
    "math"
)

func rectangularPrismVolume(diagonal, length, width float64) float64 {
    // Calculate the height of the rectangular prism using the Pythagorean theorem
    height := math.Sqrt(diagonal*diagonal - length*length - width*width)

    // Calculate the volume
    volume := length * width * height

    return volume
}

func main() {
    // Example values for diagonal, length, and width
    diagonal := 5.0
    length := 3.0
    width := 4.0

    // Calculate the volume of the rectangular prism
    volume := rectangularPrismVolume(diagonal, length, width)

    fmt.Printf("The volume of the rectangular prism with diagonal %.2f, length %.2f, and width %.2f is %.2f\n", diagonal, length, width, volume)
}
