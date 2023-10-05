function longestSubstringWithoutRepeatingChars(str) {
  let maxLength = 0;
  let start = 0;
  const charIndexMap = {};

  for (let end = 0; end < str.length; end++) {
    const char = str[end];

    if (charIndexMap[char] !== undefined) {
      // If the character is already in the substring, update the start index
      start = Math.max(start, charIndexMap[char] + 1);
    }

    // Store the index of the current character
    charIndexMap[char] = end;

    // Calculate the current substring length
    const currentLength = end - start + 1;

    // Update maxLength if necessary
    maxLength = Math.max(maxLength, currentLength);
  }

  return maxLength;
}

// Example usage:
const inputString = "abcabcbb";
const result = longestSubstringWithoutRepeatingChars(inputString);
console.log("Longest substring without repeating characters:", result); // Output: 3 (for "abc")
