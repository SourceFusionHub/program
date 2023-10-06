function calculatePentagonArea(side: number): number {
    const sqrtTerm: number = Math.sqrt(5 * (5 + 2 * Math.sqrt(5)));
    const area: number = (0.25 * sqrtTerm * Math.pow(side, 2));
    return area;
}

// Example usage
const sideLength: number = 4;
// Length of one side of the pentagon

const pentagonArea: number = calculatePentagonArea(sideLength);
console.log(`Area of the pentagon: ${pentagonArea.toFixed(2)}`);
