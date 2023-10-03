import Foundation
func average(_ a: Double, _ b: Double, _ c: Double) -> Double {
    let sum = a + b + c
    return sum / 3.0
}

func main() {
    print("Please enter three numbers separated by spaces:")
    let input = readLine()
    let numbers = input?.split(separator: " ").map { Double($0) ?? 0.0 }
    if let numbers = numbers, numbers.count == 3 {
        let result = average(numbers[0], numbers[1], numbers[2])
        print("The average of \(numbers[0]), \(numbers[1]), and \(numbers[2]) is \(result)")
    } else {
        print("Invalid input. Please enter exactly three numbers.")
    }
}
main()
