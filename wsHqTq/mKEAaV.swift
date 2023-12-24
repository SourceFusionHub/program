func findMaximum(_ num1: Int, _ num2: Int) -> Int {
    return num1 > num2 ? num1 : num2
}

print("Enter the first number:")
if let input1 = readLine(), let number1 = Int(input1) {
    print("Enter the second number:")
    if let input2 = readLine(), let number2 = Int(input2) {
        let maximum = findMaximum(number1, number2)
        print("The maximum of \(number1) and \(number2) is \(maximum)")
    }
}
