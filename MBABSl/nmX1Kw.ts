function binarySearch(arr: number[], target: number): number {
    let left = 0;
    let right = arr.length - 1;
  
    while (left <= right) {
      const mid = Math.floor((left + right) / 2);
  
      // If the target is found at the middle, return its index
      if (arr[mid] === target) {
        return mid;
      }
  
      // If the target is less than the middle element, search the left half
      if (arr[mid] > target) {
        right = mid - 1;
      }
  
      // If the target is greater than the middle element, search the right half
      else {
        left = mid + 1;
      }
    }
  
    // If the target is not found in the array, return -1 to indicate that
    return -1;
  }
  
  // Example usage
  const sortedArray = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
  const targetValue = 7;
  const result = binarySearch(sortedArray, targetValue);
  
  if (result !== -1) {
    console.log(`Target ${targetValue} found at index ${result}.`);
  } else {
    console.log(`Target ${targetValue} not found in the array.`);
  }
  