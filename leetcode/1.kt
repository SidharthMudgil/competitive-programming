// USER: SIDHARTH MUDGIL
// DATE: Thursday 26, Oct 2023
// PROBLEM: Two Sum

class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val map = mutableMapOf<Int, Int>()
        
        nums.forEachIndexed { i, v ->
            if (map.getOrDefault(target - v, -1) != -1) {
                return intArrayOf(i, map[target - v]!!)
            }

            map[v] = i
        }

        return intArrayOf()
    }
}