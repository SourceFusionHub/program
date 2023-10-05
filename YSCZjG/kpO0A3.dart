import 'dart:io';

void main() {
  // Prompt user for the length and width
  double length = promptForNumber('Enter the length of the rectangle:');
  double width = promptForNumber('Enter the width of the rectangle:');
  
  // Calculate the area
  double area = length * width;
  
  // Display the result
  print('The area of the rectangle is $area');
}


double promptForNumber(String prompt) {
  double number;
  while (true) {  // Keep prompting until a valid number is entered
    print(prompt);
    String input = stdin.readLineSync()!;
    try {
      number = double.parse(input);
      break;  // Exit the loop if parsing is successful
    } catch (e) {
      if (e is FormatException) {
        print('Invalid input. Please enter a valid number.');
      } else {
        print('An unexpected error occurred: $e');
      }
    }
  }
  return number;
}