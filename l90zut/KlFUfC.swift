import Foundation
func isPrime(_ n: Int) -> Bool {
    if n < 2 {
        return false
    }
    for i in 2...Int(sqrt(Double(n))) {
        if n % i == 0 {
            return false
        }
    }
    return true
}
func printPrime() {
    var count = 0
    var num = 2
    while count < 10 {
        if isPrime(num) {
            print(num)
            count += 1
        }
        num += 1
    }
}
func main() {
    printPrime()
}
main()
