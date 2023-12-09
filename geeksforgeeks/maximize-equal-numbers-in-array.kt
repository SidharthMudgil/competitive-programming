// USER: SIDHARTH MUDGIL
// DATE: Saturday 09, Dec 2023
// PROBLEM: Maximize the equal numbers in the Array

fun maximizeEqualNumbers(arr: IntArray, k: Int): Int {
    val map = mutableMapOf<Int, Int>()
    var res = 0
    
    arr.forEach {
        for (x in -1 * k .. k) {
         	map[it + x] = map.getOrDefault(it + x, 0) + 1
        	res = maxOf(res, map.getOrDefault(it + x, 0))   
        }
    }
    
    return res
}