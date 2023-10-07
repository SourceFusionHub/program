#include <bits/stdc++.h>
using namespace std;
int atMostSum(int arr[], int n, int k)
{
    int result = INT_MIN;
 
    for (int i = 0; i < n; i++) {
        int sum = 0;
 
        for (int j = i; j < n; j++) {
            sum += arr[j];
 
            if (sum <= k) {
                result = max(result, (j - i + 1));
            }
            else {
                break;
            }
        }
    }
 
    return result;
}
int main()
{
    int arr[] = { 1, 2, 1, 0, 1, 1, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
 
    int result = atMostSum(arr, n, k);
 
    if (result == INT_MIN) {
        cout << "No such subarray found";
    }
    else {
        cout << "The length of largest subarray having sum "
                "atmost k: "
             << result << endl;
    }
    return 0;
}
