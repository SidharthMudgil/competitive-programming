// USER: SIDHARTH MUDGIL
// DATE: Sunday 29, Oct 2023
// PROBLEM: Maximum Sub Subset with no Adjacent

fun maxSum(nums: IntArray, queries: IntArray): IntArray {
    val memo = mutableListOf<Int>(
        nums[0], 
        maxOf(nums[0], nums[1])
    )
    
    for (i in 2 ..< nums.size) {
        memo.add(maxOf(nums[i], memo[i - 1], nums[i] + memo[i - 2]))
    }
    
    val res = mutableListOf<Int>()
    queries.forEach { res.add(memo[it]) }
    return res.toIntArray()
}