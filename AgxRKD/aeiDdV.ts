import readline from 'readline';

// Function to remove duplicates from an array
function removeDuplicates<T>(array: T[]): T[] {
  const uniqueArray = new Set<T>();
  for (const element of array) {
    uniqueArray.add(element);
  }
  return Array.from(uniqueArray);
}

// Get the input array from the user
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question('Enter the array elements: ', (arrayInput) => {
  // Split the input string into an array
  const array = arrayInput.split(' ');

  // Remove duplicates from the array
  const uniqueArray = removeDuplicates(array);

  // Print the unique elements of the array to the console
  console.log(uniqueArray);

  // Close the readline interface
  rl.close();
});
