function binaryToDecimal(binaryStr: string): number {
  // Check if the input is a valid binary string
  if (!/^[01]+$/.test(binaryStr)) {
    throw new Error('Invalid binary input');
  }

  // Reverse the binary string to simplify calculation
  const reversedBinaryStr = binaryStr.split('').reverse().join('');

  let decimalValue = 0;
  for (let i = 0; i < reversedBinaryStr.length; i++) {
    if (reversedBinaryStr[i] === '1') {
      // Add 2^i to the decimal value for each '1' bit
      decimalValue += Math.pow(2, i);
    }
  }

  return decimalValue;
}

// Example usage:
const binaryNumber = "101010"; // Replace with your binary number
const decimalNumber = binaryToDecimal(binaryNumber);
console.log(`Binary ${binaryNumber} is equal to Decimal ${decimalNumber}`);
