// USER: SIDHARTH MUDGIL
// DATE: Sunday 22, Oct 2023
// PROBLEM: Mark and Toys

fun maximumToys(prices: Array<Int>, k: Int): Int {
    var res = 0
    var sum = 0
    
    prices.sorted().forEach {
        sum += it
        if (sum <= k) res++
        else return res
    }

    return res
}