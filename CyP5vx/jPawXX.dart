// Dart program to find LCM of two numbers

// Function to return gcd of two numbers
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

// Function to return LCM of two numbers
int lcm(int a, int b) {
  return (a ~/ gcd(a, b)) * b;
}

void main() {
  int a = 15, b = 20;
  print("LCM of $a and $b is ${lcm(a, b)}");
}
