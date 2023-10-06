function diagonalLength(length, width) {
    // Use the Pythagorean theorem: c^2 = a^2 + b^2
    const diagonalLength = Math.sqrt(Math.pow(length, 2) + Math.pow(width, 2));
    return diagonalLength;
  }
  
  // Example usage:
  const length = 5; // Replace with the actual length of the rectangle
  const width = 3;  // Replace with the actual width of the rectangle
  const result = diagonalLength(length, width);
  console.log(`The length of the diagonal is ${result.toFixed(2)}`);


