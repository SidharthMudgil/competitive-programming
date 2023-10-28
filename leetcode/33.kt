// USER: SIDHARTH MUDGIL
// DATE: Saturday 28, Oct 2023
// PROBLEM:33. Search in Rotated Sorted Array

// Optimized Solution
class Solution {

    fun search(nums: IntArray, target: Int): Int {
        var l = 0
        var r = nums.size - 1
        while (l <= r) {
            val m = (l + r) / 2
            if (nums[m] == target) return m
            if (nums[m] >= nums[l]) {
                if (target > nums[m] || target < nums[l]) l = m + 1
                else r = m - 1
            } else {
                if (target < nums[m] || target > nums[r]) r = m - 1 
                else l = m + 1
            }
        }
        return -1
    }
}

class Solution {
    fun IntArray.pos(target: Int): Int {
        var l = 0
        var r = this.size - 1
        while (l <= r) {
            val m = (l + r) / 2
            when {
                this[m] > target -> r = m - 1
                this[m] < target -> l = m + 1
                else -> return m
            }
        }
        return -1
    }

    fun IntArray.pivot(): Int {
        var l = 0
        var r = this.size - 1
        var p = 0
        while (l <= r) {
            val m = (l + r) / 2

            when {
                m > 0 && this[m] < this[m - 1] -> return m
                m < this.size - 1 && this[m] > this[m + 1] -> return m + 1
                m < this.size - 1 && this[m] < this[m + 1] && this[l] < this[m] -> l = m + 1
                m < this.size - 1 && this[m] < this[m + 1] && this[l] > this[m] -> r = m - 1
                this[l] == this[m] -> return p
            }
        }
        return p
    }

    fun search(nums: IntArray, target: Int): Int {
        var p = nums.pivot()
        if (p == 0)
            return nums.pos(target)

        if (target >= nums[0])
            return nums.sliceArray(0 ..< p).pos(target)

        val r = nums.sliceArray(p ..< nums.size).pos(target)
        return if (r != -1) r + p else -1
    }
}