import * as readline from "readline";

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

function isPerfect(num: number): boolean {
  let sum = 0;

  for (let i = 1; i <= num / 2; i++) {
    if (num % i === 0) {
      sum += i;
    }
  }

  return sum === num;
}

rl.question("Enter a number: ", (num) => {
  const n = parseInt(num);

  if (isPerfect(n)) {
    console.log(n + " is a perfect number");
  } else {
    console.log(n + " is not a perfect number");
  }

  rl.close();
});
