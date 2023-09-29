// USER: SIDHARTH MUDGIL
// DATE: Friday 29, Sep 2023
// TASK: Between Two Sets

fun getTotalX(a: Array<Int>, b: Array<Int>): Int {
    val low = a.max()
    val high = b.min()
    var res = 0
    
    val x = mutableListOf<Int>()
    
    for (i in low .. high) {
        val s = a.filter{ i % it == 0 }.size
        if (s == a.size) {
            x.add(i)
        }
    }
    
    x.forEach outer@{ num ->
        b.forEach {
            if (it % num != 0) return@outer
        }
        res++
    }
    
    return res
}
