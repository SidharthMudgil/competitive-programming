// USER: SIDHARTH MUDGIL
// DATE: Saturday 21, Oct 2023
// PROBLEM: Beautiful Days at the Movies

fun reverse(n: Int): Int {
    var num = 0
    var t = n
    while (t > 0) {
        var r = t % 10
        num = num * 10 + r
        t /= 10
    }   
    return num
}

fun beautifulDays(i: Int, j: Int, k: Int): Int {
    var res = 0
    
    for (n in i .. j) {
        val diff = Math.abs(n - reverse(n))
        if (diff % k == 0) res++ 
    }
    
    return res
}