import { stdin as input, stdout as output } from "process";

function getSumOfFactors(num: number): number {
  let sum = 0;

  for (let i = 1; i <= Math.sqrt(num); i++) {
    if (num % i === 0) {
      sum += i + num / i;
    }
  }

  return sum - num;
}

function isPerfect(num: number): boolean {
  return getSumOfFactors(num) === num;
}

function main() {
  output.write("Enter a number: ");

  input.on("data", (data) => {
    const num = Number(data);
    const isPerfectNum = isPerfect(num);

    output.write(`${num} is ${isPerfectNum ? "" : "not "}a perfect number\n`);

    input.pause();
  });
}

main();
