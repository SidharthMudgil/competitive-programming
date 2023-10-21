// USER: SIDHARTH MUDGIL
// DATE: Saturday 21, Oct 2023
// PROBLEM: Find Digits

fun findDigits(n: Int): Int {
    var res = 0
    n.toString().forEach {
        if (it == '0') return@forEach
        else if (n % (it.toInt() - '0'.toInt()) == 0) res++
    }
    return res
}