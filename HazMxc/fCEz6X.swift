import Foundation

// to solve a system of linear equations using Gaussian elimination
func gaussianElimination(_ augmentedMatrix: [[Double]]) -> [Double]? {
    var augmentedMatrix = augmentedMatrix
    
    let rowCount = augmentedMatrix.count
    let columnCount = augmentedMatrix[0].count - 1
    
    for pivotRow in 0..<rowCount {
        var maxRowIndex = pivotRow
        for i in pivotRow+1..<rowCount {
            if abs(augmentedMatrix[i][pivotRow]) > abs(augmentedMatrix[maxRowIndex][pivotRow]) {
                maxRowIndex = i
            }
        }
        augmentedMatrix.swapAt(pivotRow, maxRowIndex)
        
        let pivot = augmentedMatrix[pivotRow][pivotRow]
        if pivot == 0 {
            return nil
        }
        for j in pivotRow..<columnCount+1 {
            augmentedMatrix[pivotRow][j] /= pivot
        }
        
        for i in 0..<rowCount {
            if i != pivotRow {
                let factor = augmentedMatrix[i][pivotRow]
                for j in pivotRow..<columnCount+1 {
                    augmentedMatrix[i][j] -= factor * augmentedMatrix[pivotRow][j]
                }
            }
        }
    }
    
    var solution = [Double](repeating: 0, count: rowCount)
    for i in 0..<rowCount {
        solution[i] = augmentedMatrix[i][columnCount]
    }
    
    return solution
}


//reference for an example
let augmentedMatrix = [
    [2.0, 1.0, -1.0, 8.0],
    [-3.0, -1.0, 2.0, -11.0],
    [-2.0, 1.0, 2.0, -3.0]
]

if let solution = gaussianElimination(augmentedMatrix) {
    print(solution)
} else {
    print("No unique solution (singular matrix)")
}

