function sortArrayAscending(numbers: number[]): number[] {
  return numbers.sort((a, b) => a - b);
}

// Test the function
const unsortedArray: number[] = [5, 2, 9, 1, 5, 6];
const sortedArray: number[] = sortArrayAscending(unsortedArray);

console.log(sortedArray); // Output: [1, 2, 5, 5, 6, 9]
