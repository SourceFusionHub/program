#include <stdio.h>
#include <string.h>

void binaryAddition(char bin1[], char bin2[], char result[]) {
    int maxLength = strlen(bin1) > strlen(bin2) ? strlen(bin1) : strlen(bin2);
    int carry = 0;
    int sum;

    for (int i = maxLength - 1; i >= 0; i--) {
        int bit1 = i < strlen(bin1) ? bin1[i] - '0' : 0;
        int bit2 = i < strlen(bin2) ? bin2[i] - '0' : 0;
        sum = bit1 + bit2 + carry;
        result[i + 1] = sum % 2 + '0';
        carry = sum / 2;
    }

    result[0] = carry + '0';
}

int main() {
    char binary1[100], binary2[100], result[101];
    
    printf("Enter the first binary number: ");
    scanf("%s", binary1);

    printf("Enter the second binary number: ");
    scanf("%s", binary2);

    // Add binary numbers
    binaryAddition(binary1, binary2, result);

    printf("The sum of %s and %s is %s\n", binary1, binary2, result);

    return 0;
}

