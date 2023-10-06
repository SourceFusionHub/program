function checkNumberStatus(num: number): string {
    if (num > 0) {
        return 'Positive';
    } else if (num < 0) {
        return 'Negative';
    } else {
        return 'Zero';
    }
}

const numberToCheck: number = 42; 
const result: string = checkNumberStatus(numberToCheck);
console.log(`The number ${numberToCheck} is ${result}.`);
