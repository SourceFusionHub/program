#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();  
    int n = matrix[0].size();
    
    std::vector<std::vector<int>> transposed(n, std::vector<int>(m));
    
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    return transposed;
}

int main()
{
       std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
    };
    
    std::vector<std::vector<int>> transposed = transposeMatrix(matrix);
    
    for(int i = 0; i < transposed.size(); ++i) {
        for(int j = 0; j < transposed[i].size(); ++j) {
            std::cout << transposed[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

