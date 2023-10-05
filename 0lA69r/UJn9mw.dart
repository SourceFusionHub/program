void main() {
  List<int> integers = [1, 2, 3, 4, 5];
  
  // Convert list of integers to list of strings
  List<String> strings = integers.map((int number) => number.toString()).toList();
  
  // Print the list of strings
  print("List of strings: $strings");
}
