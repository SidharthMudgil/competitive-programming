// USER: SIDHARTH MUDGIL
// DATE: Friday 27, Oct 2023
// PROBLEM: 2006. Count Number of Pairs With Absolute Difference K

map.getOrDefault()class Solution {
    fun countKDifference(nums: IntArray, k: Int): Int {
        var res = 0
        val map = mutableMapOf<Int, Int>()
        nums.forEach {
            res += map.getOrDefault(it + k, 0) + map.getOrDefault(it - k, 0)
            map[it] = map.getOrDefault(it, 0) + 1
        }
        return res
    }
}