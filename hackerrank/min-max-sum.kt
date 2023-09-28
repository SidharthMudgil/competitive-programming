// USER: SIDHARTH MUDGIL
// DATE: Wednesday 27, Sep 2023
// TASK: Min Max Sum

fun miniMaxSum(arr: Array<Int>): Unit {
    var min = Int.MAX_VALUE
    var max = 0
    var sum = 0L
    for (number in arr){
        sum += number
        if (number < min) min = number
        if (number > max) max = number
    }
    println("${sum - max} ${sum - min}")
}
