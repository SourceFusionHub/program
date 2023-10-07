function sumOfEvenSquares(limit: number): number {
  let sum = 0;

  for (let i = 2; i <= limit; i += 2) {
    if (i % 2 === 0) {
      sum += i * i;
    }
  }

  return sum;
}

const limit = 10;
const result = sumOfEvenSquares(limit);
console.log(`The sum of squares of even numbers up to ${limit} is: ${result}`);
