function sumOfPrimes() {
	let sum = 0; // Sum accumulator

	for (let num = 2; num <= 100; num++) {
		let isPrime = true;

		// Check if num is divisible by any number from 2 to num - 1
		for (let i = 2; i < num; i++) {
			if (num % i === 0) {
				isPrime = false;
				break;
			}
		}

		// If isPrime is still true, num is a prime number, so add it to the sum
		if (isPrime) {
			sum += num;
		}
	}

	return sum;
}
// Example Usage:
const primeSum = sumOfPrimes();
console.log("The sum of prime numbers from 1 to 100 is:", primeSum);
