// USER: SIDHARTH MUDGIL
// DATE: Wednesday 27, Sep 2023
// TASK: Diagnol Difference

fun diagonalDifference(arr: Array<Array<Int>>): Int {
    var diag1 = 0
    var diag2 = 0
    
    for (i in 0 ..< arr.size) {
        diag1 += arr[i][i]
        diag2 += arr[i][arr.size - i - 1]
    }
    
    return Math.abs(diag1 - diag2)
}
