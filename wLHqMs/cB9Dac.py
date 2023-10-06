// Define some sample patterns for understanding user input
const patterns = [
  {
    intent: 'greeting',
    regex: /hello|hi|hey/i,
  },
  {
    intent: 'goodbye',
    regex: /bye|goodbye|see you/i,
  },
  {
    intent: 'time',
    regex: /what time is it|current time/i,
  },
];

// Function to process user input and identify the intent
function processUserInput(input) {
  input = input.toLowerCase();
  
  for (const pattern of patterns) {
    if (pattern.regex.test(input)) {
      return pattern.intent;
    }
  }
  
  return 'unknown'; // Default intent for unrecognized input
}

// Sample user input
const userInput = "Hi there! What time is it?";

// Process the user input
const intent = processUserInput(userInput);

// Respond based on the identified intent
switch (intent) {
  case 'greeting':
    console.log("Hello! How can I assist you?");
    break;
  case 'goodbye':
    console.log("Goodbye! Have a great day.");
    break;
  case 'time':
    const currentTime = new Date().toLocaleTimeString();
    console.log(`The current time is ${currentTime}.`);
    break;
  case 'unknown':
    console.log("I'm not sure how to respond to that.");
    break;
}
