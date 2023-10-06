#include <stdio.h>

int isPowerful(int n) {
    int i, j;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            if (count % 2 != 0) {
                return 0; // Not a powerful number
            }
        }
    }
    if (n > 1) {
        return 0; // If there's a prime factor left, it's not powerful
    }
    return 1; // It's a powerful number
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPowerful(n)) {
        printf("%d is a powerful number\n", n);
    } else {
        printf("%d is not a powerful number\n", n);
    }

    return 0;
}
