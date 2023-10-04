#include <iostream>
#include <vector>

int maxSumNoAdjacent(std::vector<int>& nums) {
    int n = nums.size();
    
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return nums[0];
    }
    
    int dp[n];
    
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    
    for (int i = 2; i < n; i++) {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    
    return dp[n - 1];
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    
    int result = maxSumNoAdjacent(nums);
    
    std::cout << "Maximum sum of subsequence with no adjacent elements: " << result << std::endl;
    
    return 0;
}
