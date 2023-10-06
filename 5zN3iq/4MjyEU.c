#include <stdio.h>

int main() {
  int number;

  printf("Enter a number: ");
  scanf("%d", &number);

  // Check if the last bit of the number is set.
  if (number & 1) {
    printf("%d is an odd number.\n", number);
  } else {
    printf("%d is an even number.\n", number);
  }

  return 0;
}
