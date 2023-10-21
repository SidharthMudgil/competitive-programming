// USER: SIDHARTH MUDGIL
// DATE: Saturday 21, Oct 2023
// PROBLEM: Permutation Problem

fun permutationEquation(p: Array<Int>): Array<Int> {
    val map = p.mapIndexed{ i, v -> v to i + 1 }.toMap()
    val res = mutableListOf<Int>()
    
    for (i in 1 .. p.size) {
        res.add(map[map[i]!!]!!)
    }
    
    return res.toTypedArray()
}