// Dart program that calculates the sum of all odd numbers from 1 to 100
void main() {
  int sum = 0;
  
  for (int i = 1; i <= 100; i++) {
    if (i % 2 != 0) {
      sum += i;
    }
  }
  
  print("The sum of all odd numbers from 1 to 100 is $sum");
}
