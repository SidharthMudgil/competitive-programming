// USER: SIDHARTH MUDGIL
// DATE: Sunday 29, Oct 2023
// PROBLEM: A - Frog 1

@OptIn(kotlin.ExperimentalStdlibApi::class)
fun minCost(n: Int, heights: IntArray): Int {
  val memo = mutableListOf<Int>(0)
  memo.add(Math.abs(heights[1] - heights[0]))
  for (i in 2 ..< n) {
    memo.add(
      minOf(
        Math.abs(heights[i] - heights[i - 1]) + memo[i - 1], 
        Math.abs(heights[i] - heights[i - 2]) + memo[i - 2]
      )
    )
  }
  return memo[n - 1]
}

fun main() {
    val n = readLine()!!.toInt()
    val heights = readLine()!!.split(" ").map{ it.toInt() }.toIntArray()
    print(minCost(n, heights))
}