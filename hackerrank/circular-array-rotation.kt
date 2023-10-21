// USER: SIDHARTH MUDGIL
// DATE: Saturday 21, Oct 2023
// PROBLEM: Circular Array Rotation

fun circularArrayRotation(a: Array<Int>, k: Int, queries: Array<Int>): Array<Int> {
    val res = mutableListOf<Int>()
    val map = a.mapIndexed{ i, v -> 
       (i + k) % a.size to v
    }.toMap()
    
    queries.forEach {
        res.add(map[it]!!)
    }
    return res.toTypedArray()
}
