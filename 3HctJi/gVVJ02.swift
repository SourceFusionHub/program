import Foundation

func calculatePentagonArea(sideLength: Double) -> Double {
    let apothem = sideLength / (2.0 * tan(Double.pi / 5.0))
    let area = (5 * sideLength * apothem) / 2.0
    return area
}

print("Enter the side length of the regular pentagon:")
if let input = readLine(), let sideLength = Double(input) {
    let area = calculatePentagonArea(sideLength: sideLength)
    print("The area of the regular pentagon with a side length of \(sideLength) units is \(area) square units.")
} else {
    print("Invalid input. Please enter a valid number for the side length.")
}
