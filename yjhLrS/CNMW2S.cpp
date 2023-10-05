#include <iostream>
#include <vector>

using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    
    // Calculate the total sum of all cards.
    int totalSum = 0;
    for (int i = 0; i < n; ++i) {
        totalSum += cardPoints[i];
    }
    
    // Calculate the sum of the first n-k elements from the beginning.
    int windowSum = 0;
    for (int i = 0; i < n - k; ++i) {
        windowSum += cardPoints[i];
    }
    
    int minWindowSum = windowSum;
    
    // Iterate through possible windows and keep track of the minimum sum.
    for (int i = n - k; i < n; ++i) {
        windowSum += cardPoints[i] - cardPoints[i - (n - k)];
        minWindowSum = min(minWindowSum, windowSum);
    }
    
    // The maximum points outside the chosen subarray is totalSum - minWindowSum.
    return totalSum - minWindowSum;
}

int main() {
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    
    int result = maxScore(cardPoints, k);
    
    cout << "Maximum points you can obtain: " << result << endl;
    
    return 0;
}
