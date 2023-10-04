package main

import (
    "fmt"
    "math"
    "strconv"
    "strings"
)

func findSecondLargest(arr []int) int {
    if len(arr) < 2 {
        fmt.Println("Array must have at least two elements")
        return math.MinInt32
    }

    largest := math.MinInt32
    secondLargest := math.MinInt32

    for _, num := range arr {
        if num > largest {
            secondLargest = largest
            largest = num
        } else if num > secondLargest && num != largest {
            secondLargest = num
        }
    }

    if secondLargest == math.MinInt32 {
        fmt.Println("There is no second largest element in the array.")
    }

    return secondLargest
}

func main() {
    var input string
    fmt.Print("Enter integers separated by spaces: ")
    fmt.Scanln(&input)

    inputArr := strings.Fields(input)
    arr := make([]int, len(inputArr))

    for i, numStr := range inputArr {
        num, err := strconv.Atoi(numStr)
        if err != nil {
            fmt.Println("Invalid input:", numStr, "is not a valid integer.")
            return
        }
        arr[i] = num
    }

    result := findSecondLargest(arr)
    fmt.Printf("The second largest element in the array is: %d\n", result)
}
