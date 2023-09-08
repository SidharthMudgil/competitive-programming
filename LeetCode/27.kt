// USER: SIDHARTH MUDGIL
// DATE: Friday 08, Sep 2023
// TASK: 27. Remove Element

// Using Swap
// class Solution {
//     fun removeElement(nums: IntArray, `val`: Int): Int {
//         var j = nums.size - 1
//         var k = 0

//         for (i in nums.size - 1 downTo 0) {
//             if (nums[i] == `val`) {
//                 if (i < j) {
//                     nums[j] = nums[j] + nums[i]
//                     nums[i] = nums[j] - nums[i]
//                     nums[j] = nums[j] - nums[i]
//                 }
//                 j--
//             } else {
//                 k++
//             }
//         }

//         return k
//     }
// }


class Solution {
    fun removeElement(nums: IntArray, `val`: Int): Int {
        var k = 0
        nums.forEach {
            if (it != `val`) {
                nums[k++] = it
            }
        }
        return k
    }
}