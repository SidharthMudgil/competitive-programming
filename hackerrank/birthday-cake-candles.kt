// USER: SIDHARTH MUDGIL
// DATE: Thursday 28, Sep 2023
// TASK: Birthday Cake Candles

fun birthdayCakeCandles(candles: Array<Int>): Int {
    var res = 0
    var max = 0
    
    candles.forEach {
        when {
            it == max -> res++
            it > max -> {
                max = it
                res = 1
            }
        }
    }
    
    return res
}