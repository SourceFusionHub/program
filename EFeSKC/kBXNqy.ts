function capitalizeFirstLetter(inputString: string): string {
  if (inputString.length === 0) {
    return inputString; // Return the original string if it's empty
  }

  const firstLetter = inputString[0].toUpperCase();
  const restOfString = inputString.slice(1);

  return firstLetter + restOfString;
}

// Example usage:
const input = "hello world";
const capitalized = capitalizeFirstLetter(input);
console.log(capitalized); // Output: "Hello world"
