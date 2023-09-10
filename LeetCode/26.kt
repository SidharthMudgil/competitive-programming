// USER: SIDHARTH MUDGIL
// DATE: Saturday 09, Sep 2023
// TASK: 26. Remove Duplicates from Sorted Array

// Using HashMap
// class Solution {
//     fun removeDuplicates(nums: IntArray): Int {
//         val map = nums.groupBy{it}.mapValues{it.value.size}
//         var k = 0
//         map.forEach{ it, `val` -> 
//             nums[k++] = it
//         }
//         return k
//     }
// }

class Solution {
    fun removeDuplicates(nums: IntArray): Int {
        var k = 1
        for (i in 1 ..< nums.size) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i]
            }
        }
        return k
    }
}