// USER: SIDHARTH MUDGIL
// DATE: Sunday 10, Sep 2023
// TASK: 80. Remove Duplicates from Sorted Array II

class Solution {
    fun removeDuplicates(nums: IntArray): Int {
        var k = 1
        for (i in 1 ..< nums.size) {
            if ((i == nums.size - 1) || nums[i-1] != nums[i+1]) {
                nums[k++] = nums[i]
            }
        }
        return k
    }
}

// Using HashMap
class Solution {
    fun removeDuplicates(nums: IntArray): Int {
        val map = nums.groupBy{it}.mapValues{it.value.size}
        var k = 0;
        
        map.forEach { it, cnt ->
            for (i in 0 ..< minOf(2, cnt)) {
                nums[k++] = it
            }
        }

        return k
    }
}

// Another Solution
class Solution {
    fun removeDuplicates(nums: IntArray): Int {
        var k = 1
        for (i in 1 ..< nums.size) {
            when {
                (i != nums.size - 1) && nums[i-1] == nums[i+1] -> {

                }
                else -> {
                    nums[k++] = nums[i]
                }
            }
        }
        return k
    }
}