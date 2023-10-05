// Ask the user to enter a number
const userInput = prompt("Please enter a number:");

// Convert the user input to a number
const number = parseFloat(userInput);

// Check if the number is zero
if (isNaN(number)) {
  console.log("Invalid input. Please enter a valid number.");
} else if (number === 0) {
  console.log("The entered number is zero.");
} else {
  console.log("The entered number is not zero.");
}
