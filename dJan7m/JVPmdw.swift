import Foundation

// Function to calculate the volume of a cylinder
func calculateCylinderVolume(radius: Double, height: Double) -> Double {
    let pi = 3.14159265359 
    let volume = pi * pow(radius, 2) * height
    return volume
}

let cylinderRadius = 5.0
let cylinderHeight = 10.0

let result = calculateCylinderVolume(radius: cylinderRadius, height: cylinderHeight)


print("The volume of the cylinder with radius \(cylinderRadius) and height \(cylinderHeight) is \(result) cubic units.")
