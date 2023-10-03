#include <iostream>
#include <vector>

using namespace std;

// Function to display 2D Matrix

void displayMatrix(vector<vector<int>>& matrix) {

  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix.size(); j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  
}

// Function to perform binary search on a 2D matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    if (rows == 0) {
        return false; // Empty matrix
    }

    int cols = matrix[0].size();
    if (cols == 0) {
        return false; // Empty matrix
    }

    int row = 0;
    int col = cols - 1; // Start from the top-right corner of the matrix

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return true; // Element found
        } else if (matrix[row][col] < target) {
            row++; // Move down
        } else {
            col--; // Move left
        }
    }

    return false; // Element not found
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };


    displayMatrix(matrix);

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    if (searchMatrix(matrix, target)) {
        cout << "Element " << target << " found in the matrix." << endl;
    } else {
        cout << "Element " << target << " not found in the matrix." << endl;
    }

    return 0;
}

/*
  #TEST CASES

  1).
  1 4 7 11 
  2 5 8 12 
  3 6 9 16 
  10 13 14 17 
  Enter element to search: 17
  Element 17 found in the matrix.

  2).
  1 4 7 11 
  2 5 8 12 
  3 6 9 16 
  10 13 14 17 
  Enter element to search: 12
  Element 12 found in the matrix.

  3).
  1 4 7 11 
  2 5 8 12 
  3 6 9 16 
  10 13 14 17 
  Enter element to search: -9
  Element -9 not found in the matrix.

*/