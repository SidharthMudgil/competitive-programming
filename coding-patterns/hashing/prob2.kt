// USER: SIDHARTH MUDGIL
// DATE: Tuesday 24, Oct 2023
// PROBLEM: Check if given array is subset of another array

fun isSubset(a: IntArray, b: IntArray): String {
    val map = a.groupBy{it}.mapValues{it.value.count()}.toMutableMap()
    
    b.forEach {
        if(map.getOrDefault(it, 0) > 0) {
			map[it] = map[it]!!.minus(1)
        } else {
			return "NO"
        }
    }
    
    return "YES"
}