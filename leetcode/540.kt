// USER: SIDHARTH MUDGIL
// DATE: Saturday 28, Oct 2023
// PROBLEM: 540. Single Element in a Sorted Array

class Solution {
    fun singleNonDuplicate(nums: IntArray): Int {
        var l = 0
        var r = nums.size - 1
        while (l < r) {
            val m = (l + r) / 2
            when {
                m % 2 == 0 && nums[m] == nums[m + 1] -> l = m + 1
                m % 2 == 1 && nums[m] == nums[m - 1] -> l = m + 1
                else -> r = m
            }
        }
        return nums[l]
    }
}