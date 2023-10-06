#include <stdio.h>
#include <string.h>

void toLowerCase(char *str) {
    int i = 0;
    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
        i++;
    }
}

int main() {
    char inputString[100];
    printf("Enter a string: ");
    gets(inputString);

    toLowerCase(inputString);

    printf("String in lowercase: %s\n", inputString);

    return 0;
}
