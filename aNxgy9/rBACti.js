function isPrime(n) {
  if (n <= 1) return false;
  if (n <= 3) return true;

  if (n % 2 === 0 || n % 3 === 0) return false;

  for (let i = 5; i * i <= n; i += 6) {
    if (n % i === 0 || n % (i + 2) === 0) return false;
  }

  return true;
}

function findLargestPrime(limit) {
  for (let i = limit; i >= 2; i--) {
    if (isPrime(i)) {
      return i;
    }
  }
  return null;
}

const limit = 1000000; // Change this to your desired limit
const largestPrime = findLargestPrime(limit);

if (largestPrime !== null) {
  console.log(`The largest prime number up to ${limit} is ${largestPrime}`);
} else {
  console.log(`No prime numbers found up to ${limit}`);
}
