package main

import (
	"fmt"
	"math"
)

func isKaprekar(num int) bool {
  square := num * num
	digits := int(math.Log10(float64(num))) + 1
	rDigits := digits

	for square != 0 {
		right := square % int(math.Pow(10, float64(rDigits)))
		left := square / int(math.Pow(10, float64(rDigits)))

		if right+left == num && right != 0 {
			return true
		}

		square = square / 10
    rDigits = rDigits - 1
	}

	return false
}
func main() {
	num := 45
	if isKaprekar(num) {
		fmt.Printf("%d is a Kaprekar number.\n", num)
	} else {
		fmt.Printf("%d is not a Kaprekar number.\n", num)
	}
}
