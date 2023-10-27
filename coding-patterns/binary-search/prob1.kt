// USER: SIDHARTH MUDGIL
// DATE: Friday 27, Oct 2023
// PROBLEM: find the index of the number in the array which is just greater than x and as close as possible to x.

fun findNextGreater(nums: IntArray, target: Int): Int {
    var res = -1
    var l = 0
    var r = nums.size - 1
    
    while (l <= r) {
        val m = (l + r) / 2
        when {
            nums[m] > target -> {
                r = m - 1
                res = m
            }
            nums[m] <= target -> l = m + 1
        }
    }

    return res
}