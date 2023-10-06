import 'dart:io';

void main() {
  // Prompt the user for input
  stdout.write("Enter a date (YYYY-MM-DD): ");
  
  // Read the user's input from stdin
String inputDate = stdin.readLineSync() ?? ''; // Use empty string if input is null


  try {
    // Parse the input date into a DateTime object
    DateTime date = DateTime.parse(inputDate);

    // Define a list of day names
    List<String> dayNames = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"];

    // Get the day of the week as an integer (0 for Monday, 1 for Tuesday, etc.)
    int dayOfWeekIndex = date.weekday - 1; // Adjust to match the list index

    // Get the day name from the list using the dayOfWeekIndex
    String dayName = dayNames[dayOfWeekIndex];

    // Print the result
    print('$inputDate is a $dayName');
  } catch (e) {
    print("Invalid date format. Please use YYYY-MM-DD.");
  }
}
