fun main() {
    val array1 = arrayOf(1, 2, 4, 5, 6)
    val array2 = arrayOf(2, 3, 5, 7, 8)

    val intersection = findIntersection(array1, array2)
    println("Intersection of the arrays: ${intersection.joinToString()}")
}

fun findIntersection(array1: Array<Int>, array2: Array<Int>): Set<Int> {
    val set1 = array1.toSet()
    val set2 = array2.toSet()

    return set1.intersect(set2)
}
