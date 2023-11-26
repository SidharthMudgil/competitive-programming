// USER: SIDHARTH MUDGIL
// DATE: Sunday 26, Nov 2023
// PROBLEM: 2131. Longest Palindrome by Concatenating Two Letter Words

class Solution {
    fun longestPalindrome(words: Array<String>): Int {
        val map = mutableMapOf<String, Int>()
        var res = 0
        var mid = 0

        words.forEach {
            val rev = it.reversed()
            map[it] = map.getOrDefault(it, 0) + 1
            if (it == rev) {
                val num = map.getOrDefault(it, 0)
                if (num % 2 == 0) {
                    map[it] = 0
                    res += num * 2
                } else {
                    map[it] = 1
                    res += (num - 1) * 2
                }
            } else if (it != rev && map.getOrDefault(rev, 0) > 0 && map.getOrDefault(rev, 0) > 0) {
                res += 4
                map[it] = map.getOrDefault(it, 0) - 1
                map[rev] = map.getOrDefault(rev, 0) - 1
            }
        }

        map.forEach { k, v ->
            if (v > 0 && k == k.reversed()) {
                mid = 1
                return@forEach
            }
        }

        return res + (mid * 2)
    }
}