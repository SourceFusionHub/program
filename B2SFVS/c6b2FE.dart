bool isPrime(int number) {
  if (number <= 1) {
    return false;
  }
  
  if (number == 2) {
    return true;
  }

  for (int i = 2; i <= (number / 2).floor(); i++) {
    if (number % i == 0) {
      return false;
    }
  }

  return true;
}

void main() {
  print("Enter a number:");
  var input = int.parse(stdin.readLineSync()!);

  if (isPrime(input)) {
    print("$input is a prime number.");
  } else {
    print("$input is not a prime number.");
  }
}
