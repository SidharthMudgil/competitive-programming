// USER: SIDHARTH MUDGIL
// DATE: Sunday 07, Jan 2024
// PROBLEM: 2343. Query Kth Smallest Trimmed Number

// Radix Sort
https://leetcode.com/problems/query-kth-smallest-trimmed-number/solutions/3386806/100-radix-sort-golang-detailed-explanation-with-examples/

// Sorting
class Solution {
    fun smallestTrimmedNumbers(nums: Array<String>, queries: Array<IntArray>): IntArray {
        val res = mutableListOf<Int>()

        queries.forEach { q ->
            val pq = mutableListOf<Pair<String, Int>>()
            nums.forEachIndexed { i, v -> 
                pq.add(Pair(v.toString().substring(v.length - q[1], v.length), i))
            }
            res.add(pq.sortedBy{it.first}[q[0] - 1].second)
        }

        return res.toIntArray()
    }
}