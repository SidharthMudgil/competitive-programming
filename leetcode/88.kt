// USER: SIDHARTH MUDGIL
// DATE: Thursday 07, Sep 2023
// TASK: 88. Merge Sorted Array

class Solution {
    fun merge(nums1: IntArray, m: Int, nums2: IntArray, n: Int): Unit {
        var i = m - 1
        var j = n - 1
        var k = m + n - 1

        while (j >= 0) {
            nums1[k--] = when {
                i < 0 || nums1[i] < nums2[j] -> nums2[j--]
                else -> nums1[i--]
            }
        }
    }
}