// Prompt the user to enter a number
const userInput = prompt("Enter a number:");

// Convert the user input to a number (assuming valid input)
const number = parseInt(userInput);

// Function to check if a number is a multiple of 9
function isMultipleOf9(number) {
  if (number % 9 === 0) {
    return true;
  } else {
    return false;
  }
}

// Check if the user input is a multiple of 9 and display the result
if (!isNaN(number)) {
  const resultMessage = isMultipleOf9(number)
    ? `${number} is a multiple of 9.`
    : `${number} is not a multiple of 9.`;

  alert(resultMessage);
} else {
  alert("Invalid input. Please enter a valid number.");
}
