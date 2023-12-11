// USER: SIDHARTH MUDGIL
// DATE: Monday 11, Dec 2023
// PROBLEM: Pair Search

// Optimized
fun pairSearch(nums: IntArray): Int {
    val map = mutableMapOf<Int, Int>()
    var res = 0

    nums.forEach {
        val num = nums[nums[it - 1] - 1]
        res += map.getOrDefault(num, 0)
        map[num] = map.getOrDefault(num, 0) + 1
    }

    return res
}

// Brute force
fun pairSearch(nums: IntArray): Int {
    var res = 0
    
    for (i in 0 ..< nums.size - 1) {
        for (j in i + 1 ..< nums.size) {
            if (nums[nums[nums[i] - 1] - 1] == nums[nums[nums[j] - 1] - 1]) res++
        }
    }
    
    return res
}