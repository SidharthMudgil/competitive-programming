// USER: SIDHARTH MUDGIL
// DATE: Monday 11, Dec 2023
// PROBLEM: Lamps on Numberline

fun lampsOnNumberline(lamps: Array<IntArray>, points: IntArray): IntArray {
    val map = IntArray(10000){0}
    
    lamps.forEach {
        map[it[0]]++
        map[it[1] + 1]--
    }
    
    for (i in 1 until map.size) {
        map[i] += map[i - 1]
    }
    
    return points.map{ map[it] }.toIntArray()
}