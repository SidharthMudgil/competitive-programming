// USER: SIDHARTH MUDGIL
// DATE: Friday 08, Dec 2023
// PROBLEM: 2287. Rearrange Characters to Make Target String

class Solution {
    fun rearrangeCharacters(s: String, target: String): Int {
        val sMap = s.groupingBy{ it }.eachCount().toMutableMap()
        val tMap = target.groupingBy{ it }.eachCount()
        var res = Int.MAX_VALUE
        tMap.forEach {
            res = minOf(res, sMap.getOrDefault(it.key, 0) / it.value)
        }
        return res
    }
}