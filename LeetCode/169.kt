// USER: SIDHARTH MUDGIL
// DATE: Sunday 10, Sep 2023
// TASK: 169. Majority Element

Sorting
class Solution {
    fun majorityElement(nums: IntArray): Int {
        return nums.sorted()[nums.size / 2]
    }
}

// Moore Voting Algorithm
// class Solution {
//     fun majorityElement(nums: IntArray): Int {
//         var candidate = nums[0]
//         var votes = 0

//         nums.forEach {
//             if (votes == 0) {
//                 candidate = it
//             }
//             when {
//                 candidate == it -> votes++
//                 candidate != it -> votes--
//             }
//         }
        
//         return candidate
//     }
// }


// HashMap
// class Solution {
//     fun majorityElement(nums: IntArray): Int {
//         return nums.groupBy{it}.mapValues{it.value.size}.maxBy{it.value}.key
//     }
// }