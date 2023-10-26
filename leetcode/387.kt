// USER: SIDHARTH MUDGIL
// DATE: Thursday 26, Oct 2023
// PROBLEM: 387. First Unique Character in a String

class Solution {
    fun firstUniqChar(s: String): Int {
        val m = s.groupBy{it}.mapValues{it.value.count()}.toMap()
        s.forEachIndexed { i, v -> if (m[v]!! == 1) return i}
        return -1
    }
}