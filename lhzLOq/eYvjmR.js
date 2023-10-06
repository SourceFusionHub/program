function calculateHexagonPerimeter(sideLength) {
  const perimeter = 6 * sideLength;
  return perimeter;
}

const sideLength = 5;
const perimeter = calculateHexagonPerimeter(sideLength);
console.log(`The perimeter of the regular hexagon is: ${perimeter}`);
