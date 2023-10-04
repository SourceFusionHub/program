function longestPalindrome(s) {
	if (s.length === 0) return ""; // Handle empty string case

	let start = 0; // Start index of the longest palindrome substring
	let maxLength = 1; // Length of the longest palindrome substring

	// Helper function to expand around a center
	function expandAroundCenter(left, right) {
		// checks if the characters at the left and right indices are the same and expands outwards finding palindromes
		while (left >= 0 && right < s.length && s[left] === s[right]) {
			if (right - left + 1 > maxLength) {
				// checks if the current substring is longer than the previously found longest palindrome substring
				start = left;
				maxLength = right - left + 1;
			}
			left--;
			right++;
		}
	}
	for (let i = 0; i < s.length; i++) {
		// Check for odd-length palindromes
		expandAroundCenter(i, i);

		// Check for even-length palindromes
		expandAroundCenter(i, i + 1);
	}

	// Extract the longest palindrome substring from the original string
	return s.substring(start, start + maxLength);
}

// Example usage:
const inputString = "babad";
const palindromeString = longestPalindrome(inputString);
console.log("Longest Palindrome Substring:", palindromeString);
