import * as readline from 'readline';

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

function calculateAverage(arr: number[]): number {
  if (arr.length === 0) {
    throw new Error("Array is empty. Cannot calculate average.");
  }

  const sum = arr.reduce((total, current) => total + current, 0);
  return sum / arr.length;
}

function calculateAverageFromInput() {
  rl.question("Enter numbers separated by spaces (e.g., 1 2 3 4 5): ", (input) => {
    const numbers = input.split(" ").map(Number);

    try {
      const avg = calculateAverage(numbers);
      console.log(`The average is: ${avg}`);
    } catch (error) {
      console.error(error.message);
    }

    rl.close();
  });
}

calculateAverageFromInput();
