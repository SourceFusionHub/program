fun longestCommonPrefix(strs: Array<String>): String {
    if (strs.isEmpty()) return ""
    var prefix = strs[0]
    for (i in 1 until strs.size) {
        while (strs[i].indexOf(prefix) != 0) {
            prefix = prefix.substring(0, prefix.length - 1)
            if (prefix.isEmpty()) return ""
        }
    }
    return prefix
}

fun main() {
    val strs = arrayOf("flower","flow","flight")
    val lcp = longestCommonPrefix(strs)
    println("Longest common prefix is: $lcp")
}
