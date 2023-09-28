// USER: SIDHARTH MUDGIL
// DATE: Thursday 28, Sep 2023
// TASK: Number Line Jumps

fun kangaroo(x1: Int, v1: Int, x2: Int, v2: Int): String {
    return when {
        v1 > v2 && (x1 - x2) % (v2 - v1) == 0 -> "YES"
        else -> "NO"
    }
}