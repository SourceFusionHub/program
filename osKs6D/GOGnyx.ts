import * as readlineSync from 'readline-sync';

function findMaxMinElements(numbers: number[]): { max: number, min: number } {
    if (numbers.length === 0) {
        throw new Error("Array is empty");
    }

    let max = numbers[0];
    let min = numbers[0];

    for (let i = 1; i < numbers.length; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    return { max, min };
}

// Read array elements from the user
const input = readlineSync.question("Enter array elements separated by space: ");
const numbers = input.split(" ").map(Number);

// Call the function to find max and min elements
const result = findMaxMinElements(numbers);

console.log(`Maximum element: ${result.max}`);
console.log(`Minimum element: ${result.min}`);
