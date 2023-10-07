import 'dart:io';

void main() {
  stdout.write("Enter the elements of the array (comma-separated): ");
  String? input = stdin.readLineSync();

  if (input == null) {
    print("No input provided. Exiting.");
    return;
  }

  List<String> elements = input.split(',');

  List<int> numbers = [];

  for (var element in elements) {
    try {
      int number = int.parse(element.trim());
      numbers.add(number);
    } catch (e) {
      print("Invalid input: $element is not a valid integer.");
    }
  }

  if (numbers.isEmpty) {
    print("No valid elements entered. Please provide at least one valid integer element.");
    return;
  }

  int max = numbers[0]; 

  for (int i = 1; i < numbers.length; i++) {
    if (numbers[i] > max) {
      max = numbers[i]; 
    }
  }

  print("The largest element in the array is: $max");
}
