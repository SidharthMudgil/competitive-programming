// USER: SIDHARTH MUDGIL
// DATE: Thursday 14, Sep 2023
// TASK: 55. Jump Game

// Greedy Approach
class Solution {
    fun canJump(nums: IntArray): Boolean {
        var jump = 0
        for (i in 0 ..< nums.size) {
            if (jump < i) {
                return false
            }
            jump = maxOf(jump, i + nums[i])
        }
        return true
    }
}

// Unoptimzed - First Approach
// class Solution {
//     fun canJump(nums: IntArray): Boolean {
//         var i = 0
//         while (i < nums.size) {
//             if (nums[i] >= nums.size - 1 - i || i == nums.size - 1) {
//                 return true
//             } else if (nums[i] == 0) {
//                 return false
//             }

//             var max = nums[i]
//             var jump = max
//             while (max > 0) {
//                 if (max + nums[i + max] == nums.size - 1 - i) {
//                     return true
//                 } else if (jump + nums[i + jump] < max + nums[i + max]) {
//                     jump = max
//                 }
//                 max--
//             }

//             i += jump
//         }

//         return false
//     }
// }
