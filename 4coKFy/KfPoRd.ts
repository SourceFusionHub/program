function isPalindrome(input: string): boolean {
  const cleanedInput = input.replace(/[\s.,\/#!$%\^&\*;:{}=\-_`~()]/g, '').toLowerCase();

  for (let i = 0; i < Math.floor(cleanedInput.length / 2); i++) {
    if (cleanedInput[i] !== cleanedInput[cleanedInput.length - 1 - i]) {
      return false;
    }
  }

  return true;
}

// Test cases
console.log(isPalindrome("A man, a plan, a canal, Panama")); // true
console.log(isPalindrome("race car")); // true
console.log(isPalindrome("hello world")); // false
