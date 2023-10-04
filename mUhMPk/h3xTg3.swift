import Foundation

func calculateHeptagonArea(sideLength: Double) -> Double {
    let pi = Double.pi
    let numerator = 7 * pow(sideLength, 2)
    let denominator = 4 * tan(pi / 7)
    let area = numerator / denominator
    return area
}

// Example usage
let sideLength: Double = 5.0 // Replace this with the desired side length
let area = calculateHeptagonArea(sideLength: sideLength)
print("Area of the regular heptagon: \(area)")
