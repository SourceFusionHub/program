import Foundation

func calculateTriangleArea(base: Double, height: Double) -> Double {
    // Formula for the area of a triangle: (1/2) * base * height
    return 0.5 * base * height
}

func main() {
    print("Enter the base of the triangle:")
    
    guard let baseInput = readLine(), let base = Double(baseInput) else {
        print("Invalid input for base")
        return
    }
    
    print("Enter the height of the triangle:")
    
    guard let heightInput = readLine(), let height = Double(heightInput) else {
        print("Invalid input for height")
        return
    }
    
    let area = calculateTriangleArea(base: base, height: height)
    print("The area of the triangle is: \(area)")
}

// Run the program
main()
