package main

import (
    "fmt"
)

func main() {
    var length int
    fibSeq := []int{0, 1}

    fmt.Print("Enter the length of the Fibonacci sequence: ")
    fmt.Scan(&length)

    for i := 2; i < length; i++ {
        nextNum := fibSeq[i-1] + fibSeq[i-2]
        fibSeq = append(fibSeq, nextNum)
    }

    fmt.Println("Fibonacci Sequence:")
    for _, num := range fibSeq {
        fmt.Print(num, " ")
    }
    fmt.Println()
}
