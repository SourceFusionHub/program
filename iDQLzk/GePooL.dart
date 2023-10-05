class Triangle {
  double base;
  double height;

  // Constructor to initialize the base and height
  Triangle(this.base, this.height);

  // Method to calculate the area of the triangle
  double calculateArea() {
    return 0.5 * base * height;
  }
}

void main() {
  // Instantiate a Triangle object with a given base and height
  Triangle myTriangle = Triangle(5.0, 8.0);

  // Calculate and print the area of the triangle
  double area = myTriangle.calculateArea();
  print('The area of the triangle is: $area');
}
