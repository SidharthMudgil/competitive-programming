// USER: SIDHARTH MUDGIL
// DATE: Sunday 22, Oct 2023
// PROBLEM: Picking Numbers

fun pickingNumbers(a: Array<Int>): Int {
    val m = IntArray(101) {0}
    a.forEach { m[it]++ }
    var res = 0
    
    for(i in 1 ..< 100) {
        res = maxOf(res, m[i] + m[i + 1])
    }
    
    return res
}