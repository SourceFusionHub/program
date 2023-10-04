fun <T> generatePermutations(elements: List<T>, startIndex: Int = 0): List<List<T>> {
    // Base case: if startIndex reaches end of the list, return the list
    if (startIndex == elements.size - 1) {
        return listOf(elements.toList())
    }

    val permutations = mutableListOf<List<T>>()

    for (index in startIndex until elements.size) {
        // Swap the current element with itself and all elements after it
        val newElements = elements.toMutableList()
        newElements[startIndex] = elements[index]
        newElements[index] = elements[startIndex]

        // Recursively generate permutations for the sublist
        permutations += generatePermutations(newElements, startIndex + 1)
    }

    return permutations
}
