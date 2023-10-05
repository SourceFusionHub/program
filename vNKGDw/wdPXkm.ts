function calculateHexagonArea(sideLength: number): number {
    if (sideLength <= 0 || !isFinite(sideLength)) {
        throw new Error("Invalid input. Please enter a valid positive number for side length.");
    }
    const area: number = (3 * Math.sqrt(3) * Math.pow(sideLength, 2)) / 2;
    return parseFloat(area.toFixed(2));
}
