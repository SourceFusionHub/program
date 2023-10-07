import Foundation


func calculateAverage(_ numbers: [Int]) -> Double {
    let sum = Double(numbers.reduce(0, +))
    return sum / Double(numbers.count)
}


func inputIntArray() -> [Int] {
    var numbers: [Int] = []

    while true {
        print("Enter an integer (or 'done' to calculate average):", terminator: " ")
        if let input = readLine(), let number = Int(input) {
            numbers.append(number)
        } else {
            let input = readLine()
            if input?.lowercased() == "done" && !numbers.isEmpty {
                break
            } else {
                print("Invalid input. Please enter a valid integer.")
            }
        }
    }

    return numbers
}


print("Calculate the average of an array of integers.")
let numbers = inputIntArray()

if !numbers.isEmpty {
    let average = calculateAverage(numbers)
    print("The average is: \(average)")
} else {
    print("No valid integers entered. Cannot calculate the average.")
}
