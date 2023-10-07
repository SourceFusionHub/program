import Foundation

func isArmstrongNumber(_ number: Int) -> Bool {
    var n = number
    let numDigits = String(number).count
    var sum = 0
    
    while n > 0 {
        let digit = n % 10
        sum += Int(pow(Double(digit), Double(numDigits)))
        n /= 10
    }
    
    return sum == number
}

print("Enter a number: ", terminator: "")
if let input = readLine(), let number = Int(input) {
    if isArmstrongNumber(number) {
        print("\(number) is an Armstrong number.")
    } else {
        print("\(number) is not an Armstrong number.")
    }
} else {
    print("You have entered and invalid input. Please enter a valid number.")
}
