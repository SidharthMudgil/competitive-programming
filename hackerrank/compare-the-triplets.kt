// USER: SIDHARTH MUDGIL
// DATE: Wednesday 27, Sep 2023
// TASK: Compare The Triplets

fun compareTriplets(a: Array<Int>, b: Array<Int>): Array<Int> {
    val res = Array<Int>(2){0}
    for (i in 0 ..< a.size) {
        when {
            a[i] < b[i] -> res[1] += 1
            a[i] > b[i] -> res[0] += 1
        }
    }
    return res
}
