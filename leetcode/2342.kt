// USER: SIDHARTH MUDGIL
// DATE: Thursday 07, Dec 2023
// PROBLEM: 2342. Max Sum of a Pair With Equal Sum of Digits

class Solution {

  fun Int.sum(): Int {
    var sum = 0
    var n = this
    while (n > 0) {
        sum += n % 10
        n /= 10
    }
    return sum
  }

  fun maximumSum(nums: IntArray): Int {
    val map = mutableMapOf<Int, Int>()
    var res = -1
    nums.forEach {
      val sum = it.sum()
      if (map.get(sum) != null) {
        res = maxOf(res, map.get(sum)!! + it)
      }
      map[sum] = maxOf(map.getOrDefault(sum, 0), it)
    }
    return res
  }

}