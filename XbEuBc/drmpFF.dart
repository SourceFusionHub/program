import 'dart:io';

void main() {
  
  stdout.write("Enter temperature in Celsius: ");
  
 
  String? input = stdin.readLineSync();
  
  
  double? celsius = double.tryParse(input!);
  
  if (celsius != null) {
    
    double fahrenheit = (celsius * 9 / 5) + 32;
    
    
    print("Temperature in Fahrenheit: $fahrenheit°F");
  } else {
    
    print("Invalid input. Please enter a valid number.");
  }
}
