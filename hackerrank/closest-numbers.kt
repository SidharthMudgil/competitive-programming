// USER: SIDHARTH MUDGIL
// DATE: Sunday 22, Oct 2023
// PROBLEM: Closest Numbers

fun closestNumbers(arr: Array<Int>): Array<Int> {
    var min = Int.MAX_VALUE
    var res = mutableListOf<Int>()
    arr.sort()
    for (i in 0 ..< arr.size - 1) {
        val diff = Math.abs(arr[i] - arr[i + 1])
        
        if (diff < min) {
            min = diff
            res.clear()
        }
                
        if (diff == min) {
            res.addAll(listOf(arr[i], arr[i + 1]))
        }
    }
    
    return res.toTypedArray()
}