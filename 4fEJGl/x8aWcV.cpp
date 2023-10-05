#include <iostream>
#include <vector>

bool binarySearch2D(std::vector<std::vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int left = 0, right = rows * cols - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midElement = matrix[mid / cols][mid % cols];
        
        if (midElement == target) {
            return true;
        } else if (midElement < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    
    int target = 3;
    
    if (binarySearch2D(matrix, target)) {
        std::cout << "Found " << target << " in the matrix." << std::endl;
    } else {
        std::cout << target << " not found in the matrix." << std::endl;
    }
    
    return 0;
}
