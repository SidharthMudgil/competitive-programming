// USER: SIDHARTH MUDGIL
// DATE: Monday 23, Oct 2023
// PROBLEM: 2460. Apply Operations to an Array

class Solution {
    fun applyOperations(nums: IntArray): IntArray {
        for (i in 0 ..< nums.size - 1) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2
                nums[i + 1] = 0
            }
        }
        var cnt = 0
        val res = mutableListOf<Int>()
        nums.forEach {
            if (it == 0) cnt++
            else res.add(it)
        }
        res.addAll(List(cnt){0})
        
        return res.toIntArray()
    }
}