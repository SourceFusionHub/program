function isValidRecursivePattern(pattern) {
  let index = 0;

  function parsePattern() {
    while (index < pattern.length) {
      const char = pattern[index];

      if (char === '(' && pattern[index + 1] === '?') {
        index += 2; // Skip '(?'

        // Check for recursive pattern
        if (pattern[index] === 'R' && pattern[index + 1] === ')') {
          index += 2; // Skip 'R)'
          return true;
        }

        // Continue parsing the nested pattern
        if (!parsePattern()) {
          return false;
        }
      } else if (char === ')') {
        return true;
      } else {
        index++;
      }
    }

    return false; // Unmatched '(' or unexpected end
  }

  return parsePattern() && index === pattern.length;
}

const inputPattern = "(?R)";
if (isValidRecursivePattern(inputPattern)) {
  console.log(`"${inputPattern}" is a valid regular expression pattern.`);
} else {
  console.log(`"${inputPattern}" is not a valid regular expression pattern.`);
}
