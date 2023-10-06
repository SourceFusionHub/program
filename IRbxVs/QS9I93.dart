// #1178 Build a Dart function that calculates the sum of squares of even numbers in a list of integers, excluding any negative numbers 

int sumOfSquaresOfEvenNumbers(List<int> numbers) {
  int sum = 0;
  
  for (int number in numbers) {
    if (number >= 0 && number % 2 == 0) { //it calculates the numbers which are even only and which are non negative numbers
      sum += number * number;
    }
  }
  
  return sum;
}

void main() {
  List<int> numbers = [1, 2, 23, -4, 28, 17, -7, -4]; //a sample list of numbers
  int result = sumOfSquaresOfEvenNumbers(numbers);
  print("Sum of squares of even numbers (excluding negatives): $result");
}
