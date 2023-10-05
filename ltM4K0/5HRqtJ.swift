// Function to remove all occurrences of a specific element from an array
func removeElement<T: Equatable>(_ element: T, fromArray array: inout [T]) {
    array = array.filter { $0 != element }
}

// Input: Asking the user to enter an array of elements as a space-separated string
print("Enter an array of elements (space-separated):")
if let input = readLine() {
    let elements = input.split(separator: " ").compactMap { Int($0) } // You can change the type as needed

    // Input: Asking the user to enter the specific element to remove
    print("Enter the element to remove:")
    if let elementToRemove = readLine(), let element = Int(elementToRemove) { // You can change the type as needed
        var modifiedArray = elements
        removeElement(element, fromArray: &modifiedArray)

        // Output: Displaying modified array without the specified element
        print("Modified Array: \(modifiedArray)")
    } else {
        print("Invalid element input.")
    }
} else {
    print("Invalid array input.")
}
