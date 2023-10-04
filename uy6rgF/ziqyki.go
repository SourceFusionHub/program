package main

import (
	"fmt"
	"strconv"
	"strings"
)

// Define a function to create a bar of a given length and character
func createBar(length int, char string) string {
	return strings.Repeat(char, length)
}

// Define a function to generate a bar chart from a list of data points
func generateBarChart(data []int, char string) {
	// Find the maximum value in the data
	max := 0
	for _, value := range data {
		if value > max {
			max = value
		}
	}

	// Scale the data to fit the screen width (80 characters)
	scale := 80.0 / float64(max)

	// Loop through the data and print each bar
	for _, value := range data {
		// Calculate the length of the bar
		length := int(float64(value) * scale)

		// Create the bar and print it
		bar := createBar(length, char)
		fmt.Println(bar)
	}
}

func main() {
	// Define an empty slice of data points
	data := []int{}

	// Ask the user how many data points they want to enter
	fmt.Print("How many data points do you want to enter? ")
	var n int
	fmt.Scan(&n)

	// Loop through n times and get each data point from the user
	for i := 0; i < n; i++ {
		fmt.Print("Enter data point ", i+1, ": ")
		var value int
		fmt.Scan(&value)
		data = append(data, value) // append the value to the slice
	}

	// Ask the user what character they want to use for the bars
	fmt.Print("Enter the character you want to use for the bars: ")
	var char string
	fmt.Scan(&char)

	// Generate a bar chart using the user's input
	generateBarChart(data, char)
}
