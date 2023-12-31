def matrix_multiply(matrix1, matrix2) -> list:
    """
    matrix1: (list): first matrix 
    matrix2: (list): second matrix 

    returns: (list): Multiplied Matrix
    """
    if len(matrix1[0]) != len(matrix2):
        raise ValueError("Matrix dimensions are not compatible for multiplication")

    result = [[0 for _ in range(len(matrix2[0]))] for _ in range(len(matrix1))]

    for i in range(len(matrix1)):
        for j in range(len(matrix2[0])):
            for k in range(len(matrix2)):
                result[i][j] += matrix1[i][k] * matrix2[k][j]

    return result

# Example matrices
matrix_A = [
    [1, 2],
    [3, 4],
]

matrix_B = [
    [5, 6],
    [7, 8],
]

result_matrix = matrix_multiply(matrix_A, matrix_B)

# Print the result
for row in result_matrix:
    print(row)
