// USER: SIDHARTH MUDGIL
// DATE: Friday 29, Sep 2023
// TASK: Divisible Sum Pair

// Hashing
fun divisibleSumPairs(n: Int, k: Int, ar: Array<Int>): Int {
    var m = Array<Int>(k){ 0 }
    var res = 0
    
    ar.forEach { 
        val rem = it % k
        val comp = if (rem == 0) 0 else k - rem
        res += m[comp]
        m[rem]++
    }

    return res
}

// Brute-force
fun divisibleSumPairs(n: Int, k: Int, ar: Array<Int>): Int {
    var res = 0
    
    for (i in 0 ..< n - 1) {
        for (j in i + 1 ..< n) {
            if ((ar[i] + ar[j]) % k == 0)
                res++
        }
    }
    
    return res
}
