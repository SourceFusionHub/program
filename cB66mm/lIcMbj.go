package main

import (
	"encoding/csv"
	"fmt"
	"os"
  "strings"
	"text/tabwriter"
)

func main() {
	// Open the CSV file
	file, err := os.Open("addresses.csv")
	if err != nil {
		fmt.Println("Error:", err)
		return
	}
	defer file.Close()

	// Create a CSV reader
	reader := csv.NewReader(file)

	// Read all records from CSV
	records, err := reader.ReadAll()
	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	// Print data in tabular format
	printTable(records)
}

func printTable(data [][]string) {
	// Calculate maximum column lengths
	columnLengths := make([]int, len(data[0]))
	for _, row := range data {
		for i, col := range row {
			if len(col) > columnLengths[i] {
				columnLengths[i] = len(col)
			}
		}
	}

	// Create a new tabwriter with padding and minwidth set
	w := tabwriter.NewWriter(os.Stdout, 0, 0, 2, ' ', tabwriter.AlignRight)

	// Print table header
	for i, col := range data[0] {
		fmt.Fprintf(w, "%-*s\t|", columnLengths[i], col)
	}
	fmt.Fprintln(w, "")

	// Print separator line
	for _, length := range columnLengths {
		fmt.Fprintf(w, "%s\t|", strings.Repeat("-", length))
	}
	fmt.Fprintln(w, "")

	// Print table data
	for _, row := range data[1:] {
		for i, col := range row {
			fmt.Fprintf(w, "%-*s\t|", columnLengths[i], col)
		}
		fmt.Fprintln(w, "")
	}

	// Flush the tabwriter buffer
	w.Flush()
}
