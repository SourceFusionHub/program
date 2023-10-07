// Function to calculate the area of an equilateral triangle
function equilateralTriangleArea(sideLength) {
  return (sideLength * sideLength * Math.sqrt(3)) / 4;
}

// Example usage:
const sideLength = 5; // Replace with your desired side length
const area = equilateralTriangleArea(sideLength);
console.log(`The area of the equilateral triangle is ${area}`);
