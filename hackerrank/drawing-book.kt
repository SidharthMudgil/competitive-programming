// USER: SIDHARTH MUDGIL
// DATE: Friday 29, Sep 2023
// TASK: Drawing Book

fun pageCount(n: Int, p: Int): Int {
    val back = if (n % 2 == 0) (n - p + 1) / 2 else (n - p) / 2
    return minOf(p / 2, back)
}