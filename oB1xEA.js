function findLargestElement(arr) {
    if (arr.length === 0) {
        return null; // Return null for an empty array
    }

    let largest = arr[0]; // Initialize largest with the first element

    for (let i = 1; i < arr.length; i++) {
        if (arr[i] > largest) {
            largest = arr[i]; // Update largest if a larger number is encountered
        }
    }

    return largest;
}
