fun main(args: Array<String>) {
    val matrixA = arrayOf(intArrayOf(1, 2), intArrayOf(3, 4))
    val matrixB = arrayOf(intArrayOf(5, 6), intArrayOf(7, 8))

    val productMatrix = multiplyMatrices(matrixA, matrixB)

    for (i in 0 until productMatrix.size) {
        for (j in 0 until productMatrix[0].size) {
            print(productMatrix[i][j])
            print(" ")
        }
        println()
    }
}

fun multiplyMatrices(matrixA: Array<IntArray>, matrixB: Array<IntArray>): Array<IntArray> {
    val productMatrix = Array(matrixA.size) { IntArray(matrixB[0].size) }
    for (i in 0 until matrixA.size) {
        for (j in 0 until matrixB[0].size) {
            for (k in 0 until matrixA[0].size) {
                productMatrix[i][j] += matrixA[i][k] * matrixB[k][j]
            }
        }
    }
    return productMatrix
}
