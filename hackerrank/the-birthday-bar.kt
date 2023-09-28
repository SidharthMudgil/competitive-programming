// USER: SIDHARTH MUDGIL
// DATE: Thursday 28, Sep 2023
// TASK: The Birthday Bar

fun birthday(s: Array<Int>, d: Int, m: Int): Int {
    var res = 0
    
    for (i in 0 .. s.size - m) {
        if (s.slice(i ..< i + m).sum() == d) {
            res++
        } 
    }
    
    return res
}