function calculateHypotenuse(a, b) {
  return Math.sqrt(a * a + b * b);
}

// Example usage:
const sideA = 3;
const sideB = 4;
const hypotenuse = calculateHypotenuse(sideA, sideB);
console.log(`The hypotenuse of the right triangle is ${hypotenuse}`);
