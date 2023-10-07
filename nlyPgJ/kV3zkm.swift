import Foundation
func calculateCubeVolume(sideLength: Double) -> Double {
    let volume = sideLength * sideLength * sideLength
    return volume
}

func main() {
    // Input the side length of the cube
    let sideLength = 5.0

    // Calculate the volume of the cube using the function
    let volume = calculateCubeVolume(sideLength: sideLength)

    // Print the result
    print("The volume of the cube with a side length of \(sideLength) units is \(volume) cubic units.")
}

// Call the main function to execute the program
main()
