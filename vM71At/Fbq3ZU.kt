fun main() {
    val inputString = readLine() ?: ""
    val (vowelCount, consonantCount) = countVowelsAndConsonants(inputString)
    
    println("Number of vowels: $vowelCount")
    println("Number of consonants: $consonantCount")
}

fun countVowelsAndConsonants(input: String): Pair<Int, Int> {
    val vowels = "AEIOUaeiou"
    var vowelCount = 0
    var consonantCount = 0
    
    for (char in input) {
        if (char.isLetter()) {
            if (char in vowels) {
                vowelCount++
            } else {
                consonantCount++
            }
        }
    }
    
    return Pair(vowelCount, consonantCount)
}
