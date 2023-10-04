#include <stdio.h>

int main() {
    int rows, cols;
    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    // Declare two matrices
    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];
    
    // Input for the first matrix
    printf("Enter elements for the first matrix row by row:\n");
    for (int i = 0; i < rows; i++) {
        printf("Enter elements for row %d (separated by spaces): ", i + 1);
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    // Input for the second matrix
    printf("Enter elements for the second matrix row by row:\n");
    for (int i = 0; i < rows; i++) {
        printf("Enter elements for row %d (separated by spaces): ", i + 1);
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    // Perform matrix addition
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    // Display the result
    printf("Result of matrix addition:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
