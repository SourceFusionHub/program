function calculateEquilateralTriangleArea(sideLength: number): number {
  const area = (Math.sqrt(3) / 4) * Math.pow(sideLength, 2);
  return area;
}
const sideLength = 89; // Replace with the length of the equilateral triangle's side
const area = calculateEquilateralTriangleArea(sideLength);
console.log(`The area of the equilateral triangle is ${area}`);
