function calculateCircleArea(radius: number): number {
    const pi: number = Math.PI;
    const area: number = pi * Math.pow(radius, 2);
    return area;
}

// Example usage:
const radius: number = 5;
const area: number = calculateCircleArea(radius);
console.log(`The area of the circle with radius ${radius} is ${area}`);
