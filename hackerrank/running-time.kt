// USER: SIDHARTH MUDGIL
// DATE: Sunday 22, Oct 2023
// PROBLEM: Running Time

fun runningTime(arr: Array<Int>): Int {
    var res = 0

    for (i in 1 ..< arr.size)
    {
        var j = i
        var temp = arr[i]
        while (j > 0 && temp < arr[j - 1]) {
            arr[j] = arr[j-- - 1]
            res++
        }
        arr[j] = temp
    }

    return res
}