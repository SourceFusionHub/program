function concatenateArrays<T>(arr1: T[], arr2: T[]): T[] {
  return [...arr1, ...arr2];
}


const array1: number[] = [1, 2, 3];
const array2: number[] = [4, 5, 6];
const result: number[] = concatenateArrays(array1, array2);

console.log(result); 
