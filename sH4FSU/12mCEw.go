package main

import (
    "fmt"
    "strconv"
)

func decimalToBinary(decimal int) string {
    binary := ""
    for decimal > 0 {
        remainder := decimal % 2
        binary = strconv.Itoa(remainder) + binary
        decimal = decimal / 2
    }
    return binary
}

func main() {
    var decimal int
    fmt.Print("Enter a decimal number: ")
    fmt.Scan(&decimal)

    binary := decimalToBinary(decimal)
    fmt.Printf("Binary representation: %s\n", binary)
}


