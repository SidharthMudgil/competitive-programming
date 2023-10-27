// USER: SIDHARTH MUDGIL
// DATE: Thursday 26, Oct 2023
// PROBLEM: 128. Longest Consecutive Sequence

class Solution {
    fun longestConsecutive(nums: IntArray): Int {
        val set = nums.toSet()
        var res = 0

        set.forEach {
            if (set.contains(it + 1).not()){
                var cnt = 0
                var num = it
                while (set.contains(num)) {
                    cnt++
                    num--
                }
                res = maxOf(res, cnt)
            }
        }

        return res
    }
}