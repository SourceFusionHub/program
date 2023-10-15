function sumOfCubes(limit: number): number {
  if (limit <= 0) {
    return 0; 
  }

  let sum = 0;

  for (let i = 1; i <= limit; i++) {
    sum += Math.pow(i, 3); 
  }

  return sum;
}

// Example usage:
const limit = 5; 
const result = sumOfCubes(limit);
console.log(`Sum of cubes of natural numbers up to ${limit} is: ${result}`);
