#include <iostream>
#include <vector>

int main() {
    int n;
    
    // Ask the user for the number of elements in the array
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
    
    if (n < 2) {
        std::cout << "At least two elements are required to find the second largest element." << std::endl;
        return 1;
    }
    
    std::vector<int> arr(n);
    
    std::cout << "Enter the elements of the array, one by one:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    int largest = arr[0];
    int secondLargest = arr[1];
    
    if (secondLargest > largest) {
        std::swap(largest, secondLargest);
    }
    
    for (int i = 2; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    
    std::cout << "The second largest element in the array is: " << secondLargest << std::endl;
    
    return 0;
}
