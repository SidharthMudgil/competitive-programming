// USER: SIDHARTH MUDGIL
// DATE: Tuesday 24, Oct 2023
// PROBLEM: Minimum operations to make all elements equal in an array

fun minOperation(arr: IntArray): Int {
    var res = 1
    arr.groupBy{it}.mapValues{it.value.count()}.forEach {
        if (it.value > res) res = it.value
    }
    return arr.size - res
}