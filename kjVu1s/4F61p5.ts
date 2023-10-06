function calculateConeVolume(radius: number, height: number): number {
    const pi: number = Math.PI;
    const volume: number = (1/3) * pi * Math.pow(radius, 2) * height;
    return volume;
}

// Example usage
const radius: number = 3;
// Radius of the cone
const height: number = 5;
// Height of the cone

const coneVolume: number = calculateConeVolume(radius, height);
console.log(`Volume of the cone: ${coneVolume.toFixed(2)}`);
