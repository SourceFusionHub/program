function quickSort(arr: number[]): number[] {
  if (arr.length <= 1) {
    return arr;
  }

  const pivot = arr[0];
  const left = [];
  const right = [];

  for (let i = 1; i < arr.length; i++) {
    if (arr[i] < pivot) {
      left.push(arr[i]);
    } else {
      right.push(arr[i]);
    }
  }

  return [...quickSort(left), pivot, ...quickSort(right)];
}

function measurePerformance(): void {
  const arrSize = 10000; // Change this to your desired array size
  const unsortedArray: number[] = [];

  // Generate a random unsorted array
  for (let i = 0; i < arrSize; i++) {
    unsortedArray.push(Math.random());
  }

  // Measure the time taken to sort the array
  const startTime = performance.now();
  const sortedArray = quickSort(unsortedArray);
  const endTime = performance.now();

  const elapsedTime = endTime - startTime;

  console.log(`Sorted ${arrSize} elements in ${elapsedTime.toFixed(4)} milliseconds.`);
}

// Measure the performance of the quickSort function
measurePerformance();
