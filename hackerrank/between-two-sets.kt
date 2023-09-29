// USER: SIDHARTH MUDGIL
// DATE: Friday 29, Sep 2023
// TASK: Between Two Sets

// gcd
fun _gcd(a: Int, b: Int): Int {
    if (b == 0)
        return a
        
    _gcd(b, a % b)
}

fun _lcm(a: Int, b: Int): Int {
    return return (a * b) / _gcd(a, b)
}

fun getTotalX(a: Array<Int>, b: Array<Int>): Int {
    var lcm = a.reduce{ acc, i -> _lcm(acc, i) }
    val gcd = b.reduce{ acc, i -> _gcd(acc, i) }
    var res = 0
    
    for (i in lcmA..gcdB step lcmA) {
        if (gcdB % i == 0) {
            count++
        }
    }

    return res
}

// loops
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
