function sortNumbersAscending(numbers: number[]): number[] {
  return numbers.slice().sort((a, b) => a - b);
}

// Example usage:
const unsortedArray = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5];
const sortedArray = sortNumbersAscending(unsortedArray);
console.log(sortedArray); // Output: [1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9]
