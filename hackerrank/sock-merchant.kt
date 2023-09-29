// USER: SIDHARTH MUDGIL
// DATE: Friday 29, Sep 2023
// TASK: Sock Merchant

fun sockMerchant(n: Int, ar: Array<Int>): Int {
    var res = 0
    
    ar.groupingBy{ it }.eachCount().forEach {
        res += it.value / 2
    }
    
    return res
}
