//Implement a C++ function to find the median of an array of numbers.
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

double findMedian(std::vector<double> nums) {
    if (nums.empty()) {
        throw std::invalid_argument("Cannot find median of empty array");
    }
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n % 2 == 0) {
        return (nums[n/2 - 1] + nums[n/2]) / 2.0;
    } else {
        return nums[n/2];
    }
}

int main() {
    std::vector<double> nums;
    double num;
    std::cout << "Enter numbers (enter a non-number to stop):" << std::endl;
    while (std::cin >> num) {
        nums.push_back(num);
    }
    try {
        double median = findMedian(nums);
        std::cout << "Median: " << median << std::endl;
    } catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
