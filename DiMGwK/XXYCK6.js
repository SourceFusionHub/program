function isPerfectSquare(num) {
    if (num < 0) {
        return false;
    }

    if (num === 0) {
        return true;
    }

    for (let i = 1; i * i <= num; i++) {
        if (i * i === num) {
            return true;
        }
    }

    return false;
}

const num1 = 16;
console.log(`${num1} is a perfect square: ${isPerfectSquare(num1)}`); // true

const num2 = 17;
console.log(`${num2} is a perfect square: ${isPerfectSquare(num2)}`); // false
