// USER: SIDHARTH MUDGIL
// DATE: Friday 20, Oct 2023
// PROBLEM: Utopian Tree

fun utopianTree(n: Int): Int {
    var height = 1
    for (i in 1 .. n) {
        when {
            i % 2 == 0 -> height++
            else -> height *= 2
        }
    }
    return height
}