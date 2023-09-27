// USER: SIDHARTH MUDGIL
// DATE: Wednesday 27, Sep 2023
// TASK: Staircase

fun staircase(n: Int): Unit {
    for (i in 1 .. n) {
        print(" ".repeat(n - i))
        println("#".repeat(i))
    }
}