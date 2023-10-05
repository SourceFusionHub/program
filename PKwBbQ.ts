import * as readline from 'readline';

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

function sumEvenFibonacci(limit: number): number {
  let sum = 0;
  let prev = 1;
  let current = 2;

  while (current <= limit) {
    if (current % 2 === 0) {
      sum += current;
    }

    const next = prev + current;
    prev = current;
    current = next;
  }

  return sum;
}

rl.question('Enter the limit: ', (limitInput) => {
  const limit = parseInt(limitInput, 10);

  if (isNaN(limit) || limit < 2) {
    console.log('Invalid input. Please enter a positive integer greater than or equal to 2.');
  } else {
    const result = sumEvenFibonacci(limit);
    console.log(`Sum of even Fibonacci numbers up to ${limit}: ${result}`);
  }

  rl.close();
});
