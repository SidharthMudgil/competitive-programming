// USER: SIDHARTH MUDGIL
// DATE: Sunday 22, Oct 2023
// PROBLEM: Tutorial Intro

fun introTutorial(V: Int, arr: Array<Int>): Int {
    arr.forEachIndexed {i, v -> 
        if (V == v) return i
    }
    return -1
}