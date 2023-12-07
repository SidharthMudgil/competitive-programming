// USER: SIDHARTH MUDGIL
// DATE: Thursday 07, Dec 2023
// PROBLEM: 49. Group Anagrams

class Solution {
    fun groupAnagrams(strs: Array<String>): List<List<String>> {
        val aMap = mutableMapOf<String, MutableList<String>>()

        strs.forEach {
            val sStr = it.toList().sorted().joinToString("")
            aMap[sStr] = aMap.getOrDefault(sStr, mutableListOf()).apply{ add(it) }
        }

        return aMap.map{ it.value }
    }
}