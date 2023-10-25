// USER: SIDHARTH MUDGIL
// DATE: Tuesday 24, Oct 2023
// PROBLEM: Check if the given array contains duplicate elements within k distance from each other

fun kDistance(arr: IntArray, k: Int): String {
    val cnt = arr.groupBy{it}.mapValues{ it.value.count() }.toMutableMap()
    
    arr.forEachIndexed { i, v ->
        if (cnt.getOrDefault(v, 0) > 1) {
            cnt[v] = cnt[v]!! - 1
            
            if (i + k >= arr.size || arr[i + k] != v)
            	return "NO"
        }
    }

    return "YES"
}