function findIntersection(arr1, arr2) {
  // Use a Set to store unique elements from the first array
  const set1 = new Set(arr1);

  // Use a Set to store common elements found in both arrays
  const intersection = [];

  // Iterate through the second array
  for (const element of arr2) {
    // If the element exists in set1, it's a common element
    if (set1.has(element)) {
      intersection.push(element);
      // Remove the element from set1 to avoid duplicates in the intersection
      set1.delete(element);
    }
  }

  return intersection;
}

// Example usage:
const array1 = [1, 2, 3, 4, 5];
const array2 = [3, 4, 5, 6, 7];
const result = findIntersection(array1, array2);
console.log("Intersection:", result); // Output: [3, 4, 5]
