// USER: SIDHARTH MUDGIL
// DATE: Sunday 22, Oct 2023
// PROBLEM: Sherlock and Array

fun balancedSums(arr: Array<Int>): String {
    var lSum = 0
    val sum = arr.sum()
    
    for (i in 0 ..< arr.size) {
        val rSum = sum - lSum - arr[i]
        if (lSum == rSum) return "YES"
        lSum += arr[i]
    }

    return "NO"
}

fun balancedSums(arr: Array<Int>): String {
    val pSum = mutableMapOf<Int, Int>()
    val sSum = mutableMapOf<Int, Int>()
    
    pSum[0] = 0
    sSum[arr.size - 1] = 0
    
    for (i in 1 ..< arr.size) {
        pSum[i] = pSum[i - 1]!! + arr[i - 1]
        sSum[arr.size - 1 - i] = sSum[arr.size - i]!! + arr[arr.size - i]
    }
    
    for (i in 0 ..< arr.size) {
        if (pSum[i]!! == sSum[i]!!) return "YES"
    }

    return "NO"
}   