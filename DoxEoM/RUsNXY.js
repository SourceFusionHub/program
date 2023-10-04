// Function to calculate GCD using the Euclidean algorithm
function calculateGCD(a, b) {
    while (b !== 0) {
        const temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Get user input

const prompt=require("prompt-sync")({sigint:true}); 
const num1 = parseInt(prompt("Enter the first number: "));
const num2 = parseInt(prompt("Enter the second number: "));

// Check if both inputs are valid numbers
if (!isNaN(num1) && !isNaN(num2)) {
    // Calculate and display the GCD
    const gcd = calculateGCD(num1, num2);
    console.log(`The GCD of ${num1} and ${num2} is ${gcd}`);
} else {
    console.log("Please enter valid numbers.");
}
