function longestCommonPrefix(strings: string[]): string {
  if (strings.length === 0) {
      return "";
  }

  // Sort the array to ensure that the shortest string is first
  strings.sort((a, b) => a.length - b.length);

  const shortestString = strings[0];
  let longestPrefix = "";

  for (let i = 0; i < shortestString.length; i++) {
      const currentChar = shortestString[i];

      // Check if the current character is common to all strings
      if (strings.every(str => str[i] === currentChar)) {
          longestPrefix += currentChar;
      } else {
          break; // Stop when a mismatch is found
      }
  }

  return longestPrefix;
}

// Example usage:
const strings = ["flower", "flour", "flourish"];
const commonPrefix = longestCommonPrefix(strings);
console.log("Longest common prefix:", commonPrefix); // Output: "flo"
