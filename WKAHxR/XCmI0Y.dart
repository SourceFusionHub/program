int sumOfCubes(List<int> numbers) {
  int sum = 0;
  for (int number in numbers) {
    sum += number * number * number; // cube the number and add to the sum
  }
  return sum;
}

void main() {
  List<int> numbers = [1, 2, 3, 4, 5];
  int result = sumOfCubes(numbers);
  print('Sum of cubes: $result'); 
}
