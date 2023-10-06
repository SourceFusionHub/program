function isDigitString(str: string): boolean {
  // Remove any leading or trailing whitespace from the string.
  str = str.trim();

  // Convert the string to an integer.
  const num = parseInt(str);

  // If the string contains any non-digit characters, then `parseInt()` will return `NaN`.
  // Otherwise, it will return a valid integer.
  return !isNaN(num);
}

// Example usage:
const str1 = "1234567890";
const str2 = "abc123";

console.log(isDigitString(str1)); // true
console.log(isDigitString(str2)); // false
