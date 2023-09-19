// USER: SIDHARTH MUDGIL
// DATE: Tuesday 19, Sep 2023
// TASK: 238. Product of Array Except Self


// Approach 2
class Solution {
    fun productExceptSelf(nums: IntArray): IntArray {
        val res = IntArray(nums.size) { 1 }
        var pre = 1
        var suf = 1
        
        for (i in 0 ..< nums.size) {
            res[i] *= pre
            pre *= nums[i]
            res[nums.size - 1 - i] *=  suf
            suf *= nums[nums.size - 1 - i]
        }

        return res
    }
}

// Approach 1
class Solution {
    fun productExceptSelf(nums: IntArray): IntArray {
        val res = IntArray(nums.size) { 1 }
        var suf = 1
        
        for (i in 1 ..< nums.size) {
            res[i] = res[i - 1] * nums[i - 1]
        }

        for (i in nums.size - 1 downTo 0) {
            res[i] *=  suf
            suf *= nums[i]
        }

        return res
    }
}
