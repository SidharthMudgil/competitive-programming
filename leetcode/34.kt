// USER: SIDHARTH MUDGIL
// DATE: Friday 27, Oct 2023
// PROBLEM: 34. Find First and Last Position of Element in Sorted Array

class Solution {
    fun IntArray.getPos(target: Int, left: Boolean = true): Int {
        var flag = -1
        var l = 0
        var r = this.size - 1
        while (l <= r) {
            val m = (l + r) / 2
            when {
                this[m] > target -> r = m - 1
                this[m] < target -> l = m + 1
                else -> {
                    if (left) r = m - 1 
                    else l = m + 1
                    flag = m
                }
            }
        }

        return flag
    }

    fun searchRange(nums: IntArray, target: Int): IntArray {
        return intArrayOf(nums.getPos(target), nums.getPos(target, false))
    }
}