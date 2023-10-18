function findCommonElements(array1, array2) {
  const set1 = new Set(array1);
  const set2 = new Set(array2);
  const commonElements = [...set1].filter(element => set2.has(element));
  return commonElements;
}

const array1 = [1, 2, 3, 4, 5];
const array2 = [3, 4, 5, 6, 7];
const commonElements = findCommonElements(array1, array2);
console.log(commonElements); // Output: [3, 4, 5]
