// USER: SIDHARTH MUDGIL
// DATE: Wednesday 27, Sep 2023
// TASK: Min Max Sum

fun miniMaxSum(arr: Array<Int>): Unit {
    arr.sort()
    val min = arr.take(4).sum()
    val max = arr.takeLast(4).sum()
    print("$min $max")
}
