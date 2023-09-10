

class Solution {
    fun majorityElement(nums: IntArray): Int {
        var candidate = nums[0]
        var votes = 0

        nums.forEach {
            if (votes == 0) {
                candidate = it
            }
            when {
                candidate == it -> votes++
                candidate != it -> votes--
            }
        }
        
        return candidate
    }
}