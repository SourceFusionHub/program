function sumOfOddNumbers(arr: number[]): number {
  // Initialize a variable to store the sum
  let sum = 0;

  // Loop through the array
  for (let i = 0; i < arr.length; i++) {
    // Check if the current element is odd
    if (arr[i] % 2 !== 0) {
      // Add the odd number to the sum
      sum += arr[i];
    }
  }

  return sum;
}

// Example usage:
const numbers = [1, 2, 3, 4, 5, 6, 7];
const result = sumOfOddNumbers(numbers);
console.log(result); // Output will be 16 (1 + 3 + 5 + 7)
