// USER: SIDHARTH MUDGIL
// DATE: Thursday 26, Oct 2023
// PROBLEM: CSUMQ - Cumulative Sum Query

fun csumq(nums: IntArray, queries: Array<IntArray>): IntArray {
    val map = mutableMapOf<Int, Int>(-1 to 0)
    var sum = 0
    nums.forEachIndexed { i, v ->
        sum += v
        map[i] = sum
    }
    
    val res = mutableListOf<Int>()
    queries.forEach {
        res.add(map[it[1]]!! - map[it[0] - 1]!!)
    }
    
    return res.toIntArray()
}

fun main() {
    val n = readLine()!!.toInt()
    val nums = readLine()!!.split(" ").map{it.toInt()}.toIntArray()
    val queries = mutableListOf<IntArray>()
    val q = readLine()!!.toInt()
    repeat(q) {
        queries.add(readLine()!!.split(" ").map{it.toInt()}.toIntArray())
    }
    csumq(nums, queries.toTypedArray()).forEach(::println)
}