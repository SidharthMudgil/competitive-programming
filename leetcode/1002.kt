// USER: SIDHARTH MUDGIL
// DATE: Thursday 26, Oct 2023
// PROBLEM: 1002. Find Common Characters

class Solution {
    fun commonChars(words: Array<String>): List<String> {
        val maps = mutableListOf<Map<Char, Int>>()
        words.forEach { word ->
            maps.add(word.groupBy{it}.mapValues{it.value.count()}.toMap())
        }

        val res = mutableListOf<String>()
        maps[0].forEach {
            var min = it.value
            for (i in  1 ..< maps.size) {
                if (min > maps[i].getOrDefault(it.key, 0))
                    min = maps[i].getOrDefault(it.key, 0)
            }
            res.addAll(List(min){i -> it.key.toString()})
        }

        return res
    }
}