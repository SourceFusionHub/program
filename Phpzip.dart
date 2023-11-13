import 'dart:io';

void main() {
  stdout.write('Enter an integer: ');
  String userInput = stdin.readLineSync() ?? ""; // Read user input as a string

  try {
    int number = int.parse(userInput);
    int digitSum = calculateDigitSum(number);
    print('The sum of the digits of $number is: $digitSum');
  } catch (e) {
    print('Invalid input. Please enter a valid integer.');
  }
}

int calculateDigitSum(int number) {
  int sum = 0;
  while (number != 0) {
    sum += number % 10; // Get the last digit and add it to the sum
    number ~/= 10; // Remove the last digit from the number
  }
  return sum;
}
