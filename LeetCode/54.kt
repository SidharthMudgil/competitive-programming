// USER: SIDHARTH MUDGIL
// DATE: Saturday 16, Sep 2023
// TASK: 54. Jump Game II

// Greedy
class Solution {
    fun jump(nums: IntArray): Int {
        var jumps = 0
        var bestJump = 0
        var jump = 0
        for (i in 0 ..< nums.size - 1) {
            bestJump = maxOf(bestJump, i + nums[i])

            if (i == jump) {
                jumps++
                jump = bestJump
            }
        }
        return jumps 
    }
}