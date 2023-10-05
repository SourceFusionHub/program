#include <stdio.h>

int maxProductSubarray(int arr[], int n) {
    if (n == 0) {
        return 0;
    }

    int maxEndingHere = 1;
    int minEndingHere = 1;
    int maxSoFar = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            maxEndingHere = maxEndingHere * arr[i];
            minEndingHere = (minEndingHere * arr[i] > 1) ? minEndingHere * arr[i] : 1;
        } else if (arr[i] == 0) {
            maxEndingHere = 1;
            minEndingHere = 1;
        } else {
            int temp = maxEndingHere;
            maxEndingHere = (minEndingHere * arr[i] > 1) ? minEndingHere * arr[i] : 1;
            minEndingHere = temp * arr[i];
        }

        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
        }
    }

    return maxSoFar;
}

int main() {
    int arr[] = {2, 3, -2, 4, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = maxProductSubarray(arr, n);
    printf("Maximum product subarray is: %d\n", result);
    return 0;
}
