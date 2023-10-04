package main

import (
    "fmt"
    "math"
)

func calculateTriangleArea(a, b, c float64) float64 {
    s := (a + b + c) / 2.0
    area := math.Sqrt(s * (s - a) * (s - b) * (s - c))
    return area
}

func main() {
    var sideA, sideB, sideC float64

    fmt.Print("Enter the length of side A: ")
    fmt.Scan(&sideA)

    fmt.Print("Enter the length of side B: ")
    fmt.Scan(&sideB)

    fmt.Print("Enter the length of side C: ")
    fmt.Scan(&sideC)

    area := calculateTriangleArea(sideA, sideB, sideC)
    fmt.Printf("The area of the triangle is: %.2f\n", area)
}
