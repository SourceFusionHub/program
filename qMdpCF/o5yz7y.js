// Get input from the user for three numbers
const num1 = parseFloat(prompt("Enter the first number:"));
const num2 = parseFloat(prompt("Enter the second number:"));
const num3 = parseFloat(prompt("Enter the third number:"));

// Check if the input is valid numbers
if (!isNaN(num1) && !isNaN(num2) && !isNaN(num3)) {
  // Calculate the product of the three numbers
  const product = num1 * num2 * num3;

  // Display the result
  console.log(`The product of ${num1}, ${num2}, and ${num3} is: ${product}`);
} else {
  console.log("Invalid input. Please enter valid numbers.");
}

