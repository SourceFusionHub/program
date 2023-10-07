import 'dart:io';

void main() {
  print('Enter the length of the parallelepiped:');
  double length = double.parse(stdin.readLineSync()!);

  print('Enter the width of the parallelepiped:');
  double width = double.parse(stdin.readLineSync()!);

  print('Enter the height of the parallelepiped:');
  double height = double.parse(stdin.readLineSync()!);

  double volume = calculateVolume(length, width, height);
  print('The volume of the parallelepiped is: $volume cubic units');
}

double calculateVolume(double length, double width, double height) {
  return length * width * height;
}
