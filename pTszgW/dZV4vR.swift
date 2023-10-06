func celsiusToFahrenheit(_ celsius: Double) -> Double {
    return (celsius * 9/5) + 32
}

func getInput() -> Double {
    while true {
        print("Enter temperature in Celsius: ", terminator: "")
        if let input = readLine(), let celsius = Double(input) {
            return celsius
        } else {
            print("Invalid input. Please enter a valid number.")
        }
    }
}

let celsius = getInput()
let fahrenheit = celsiusToFahrenheit(celsius)
print("\(celsius) degrees Celsius is equal to \(fahrenheit) degrees Fahrenheit.")
