#include <stdio.h>

int main() {
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);

  // Check if the number is prime
  int is_prime = 1;
  for (int i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
      is_prime = 0;
      break;
    }
  }

  // Check if the number is even or odd
  int is_even = num % 2 == 0;
  int is_odd = !is_even;

  // Check if the number is composite
  int is_composite = num > 1 && !is_prime;

  // Print the results
  printf("%d is prime: %d\n", num, is_prime);
  printf("%d is even: %d\n", num, is_even);
  printf("%d is odd: %d\n", num, is_odd);
  printf("%d is composite: %d\n", num, is_composite);

  return 0;
}
