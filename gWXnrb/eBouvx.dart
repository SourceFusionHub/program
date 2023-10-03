double calculateTrapeziumArea(double base1, double base2, double height) {
  double area = 0.5 * (base1 + base2) * height;
  return area;
}

void main() {
  double base1 = 5.0; // Replace with the actual length of the first base
  double base2 = 7.0; // Replace with the actual length of the second base
  double height = 4.0; // Replace with the actual height
  
  double area = calculateTrapeziumArea(base1, base2, height);
  print('The area of the trapezium is: $area');
}
