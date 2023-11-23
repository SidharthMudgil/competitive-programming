// USER: SIDHARTH MUDGIL
// DATE: Thursday 23, Nov 2023
// PROBLEM: 2657. Find the Prefix Common Array of Two Arrays

// Optimized
fun findThePrefixCommonArray(A: IntArray, B: IntArray): IntArray {
    val map1 = mutableMapOf<Int, Int>()
    val map2 = mutableMapOf<Int, Int>()
    val res = mutableListOf<Int>()
    var cnt = 0
    for (i in 0 ..< B.size) {
        map1[A[i]] = 1
        map2[B[i]] = 1
        
        if (map2.getOrDefault(A[i], 0) != 0) cnt++
        if (map1.getOrDefault(B[i], 0) != 0 && A[i] != B[i]) cnt++
        
        res.add(cnt)
    }
    
    return res.toIntArray()
}

class Solution {
    fun findThePrefixCommonArray(A: IntArray, B: IntArray): IntArray {
        val map1 = A.mapIndexed{ i, v -> v to i }.toMap()
        val c = mutableListOf<Int>()
        
        for (i in 0 ..< B.size) {
            var cnt = 0
            
            for (j in 0 .. i) {
                if (map1.getOrDefault(B[j], B.size) <= i)
                    cnt++
            }
            
            c.add(cnt)
        }
        
        return c.toIntArray()
    }
}