// USER: SIDHARTH MUDGIL
// DATE: Sunday 07, Jan 2024
// PROBLEM: 216. Combination Sum III

// Backtracking
class Solution {
    fun findCombination(i: Int, sum: Int, list: List<Int>, k: Int, n: Int, res: MutableList<List<Int>>) {
        when {
            list.size > k || sum > n -> return
            list.size == k && sum == n -> {
                res.add(list)
                return
            }
        }
        
        for (j in i .. 9) {
            findCombination(j + 1, sum + j, list + j, k, n, res)
        }
    }

    fun combinationSum3(k: Int, n: Int): List<List<Int>> {
        val res = mutableListOf<List<Int>>()       
        findCombination(1, 0, emptyList(), k, n, res)
        return res
    }
}

// Bruteforce with Bitmasking
class Solution {
    fun Int.count(): Int {
        var cnt = 0
        var tmp = this

        while (tmp > 0) {
            tmp = tmp and (tmp - 1)
            cnt++
        }

        return cnt
    }

    fun combinationSum3(k: Int, n: Int): List<List<Int>> {
        val res = mutableSetOf<List<Int>>()       
        var bits = 1 shl 9
 
        while (bits > 0) {
            if (bits.count() != k) {
                bits--
                continue
            }

            val li = mutableListOf<Int>()

            for (i in 1 .. 9) {
                if ((bits and (1 shl i - 1)) != 0) {
                    li.add(i)
                }
            }

            if (li.sum() == n) {
                res.add(li)
            }

            bits--
        }

        return res.toList()
    }
}