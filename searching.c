#include <stdio.h>

int main() {
    // number of elements
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // array
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i);
        scanf("%d", &arr[i]);
    }

    // number to be found
    int newNum;
    printf("Enter the element to be found: ");
    scanf("%d", &newNum);

    // searching
    int found = 0; // Initialize a variable to track if the element is found
    for (int i = 0; i < n; i++) {
        if (arr[i] == newNum) {
            found = 1; // Set found to 1 if the element is found
            printf("Element found!!");
            break;
        }
    }

    if (!found) { // Check if the element was not found
        printf("Element not found.");
    }

    return 0;
}
