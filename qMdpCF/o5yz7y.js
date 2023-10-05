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

// In this code:

// We use the prompt function to display a dialog box to the user and get their input for three numbers. We use parseFloat to convert the input strings into floating-point numbers.

// We check if the input is valid numbers using isNaN (Is Not a Number) function. If all three inputs are valid numbers, we proceed to calculate the product.

// If the inputs are valid, we calculate the product of the three numbers using the * operator.

// Finally, we display the calculated product in the console. If the user enters invalid input (e.g., non-numeric values), it will display "Invalid input. Please enter valid numbers."