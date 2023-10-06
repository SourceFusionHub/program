const val ALPHABET_SIZE = 256  // Assuming an extended ASCII character set

fun createBadCharacterTable(pattern: String): IntArray {
    val table = IntArray(ALPHABET_SIZE) { -1 }
    for (i in pattern.indices) {
        table[pattern[i].toInt()] = i
    }
    return table
}

fun boyerMooreSearch(text: String, pattern: String): List<Int> {
    val m = pattern.length
    val n = text.length
    val badChar = createBadCharacterTable(pattern)

    val occurrences = mutableListOf<Int>()

    var s = 0  // s is the shift of the pattern with respect to text
    while (s <= n - m) {
        var j = m - 1

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--
        }

        if (j < 0) {
            occurrences.add(s)
            s += if (s + m < n) m - badChar[text[s + m].toInt()] else 1
        } else {
            s += maxOf(1, j - badChar[text[s + j].toInt()])
        }
    }
    return occurrences
}

