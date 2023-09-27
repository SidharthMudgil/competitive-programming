// USER: SIDHARTH MUDGIL
// DATE: Wednesday 27, Sep 2023
// TASK: A Very Big Sum

fun aVeryBigSum(ar: Array<Long>): Long {
    return ar.reduce {it, sum -> it + sum}
}