package main

import (
	"fmt"
	"strconv"
)

func celsiusToFahrenheit(celsius float64) float64 {
	return (celsius * 9/5) + 32
}

func main() {
	var input string
	var celsius float64

	fmt.Print("Enter temperature in Celsius: ")
	fmt.Scanln(&input)

	// Convert input to float64, handle non-numeric input
	celsius, err := strconv.ParseFloat(input, 64)
	if err != nil {
		fmt.Println("Invalid input. Please enter a valid number.")
		return
	}

	fahrenheit := celsiusToFahrenheit(celsius)
	fmt.Printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit)
}
