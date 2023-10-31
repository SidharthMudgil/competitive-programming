// USER: SIDHARTH MUDGIL
// DATE: Sunday 29, Oct 2023
// PROBLEM: A - Frog 2

@OptIn(kotlin.ExperimentalStdlibApi::class)
fun minCost(n: Int, k: Int, heights: IntArray): Int {
  val memo = mutableListOf<Int>(0)
  memo.add(Math.abs(heights[1] - heights[0]))
  for (i in 2 ..< n) {
    var res = Int.MAX_VALUE
    var j = 1
    while (j <= k && i - j >= 0) {
      res = minOf(res, Math.abs(heights[i] - heights[i - j])  + memo[i - j])
      j++
    }
    memo.add(res)
  }
  return memo[n - 1]
}

fun main() {
    val (n, k) = readLine()!!.split(" ").map{ it.toInt() }.toIntArray()
    val heights = readLine()!!.split(" ").map{ it.toInt() }.toIntArray()
    print(minCost(n, k, heights))
}