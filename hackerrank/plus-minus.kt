// USER: SIDHARTH MUDGIL
// DATE: Wednesday 27, Sep 2023
// TASK: Plus Minus


fun plusMinus(arr: Array<Int>): Unit {
    val res = Array<Int>(3){ 0 }
    
    arr.forEach {
        when {
            it > 0 -> res[0] += 1
            it < 0 -> res[1] += 1
            else -> res[2] += 1
        }
    }
    
    res.forEach {
        println("${it / arr.size.toFloat()}")
    }
}