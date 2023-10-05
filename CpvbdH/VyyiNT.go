package main

import (
	"math"
)

func hpVolume(slength, height float64) float64 {
	// Calculating the area of hexagon's base
	basearea := 3 * math.Sqrt(3) * math.Pow(slength, 2) / 2
	// Calculating the volume of prism using formula,
  // V = basearea * height
	volume := basearea * height
	return volume
}
