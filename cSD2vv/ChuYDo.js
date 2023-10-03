function isAlphanumeric(input) {
  // Define a regular expression that matches only alphanumeric characters
  var alphanumericRegex = /^[a-zA-Z0-9]+$/;

  // Test the input string against the regular expression
  return alphanumericRegex.test(input);
}

// Example usage:
var str1 = "Anurag2001";
var str2 = "12345!";
console.log(isAlphanumeric(str1)); // true
console.log(isAlphanumeric(str2)); // false
