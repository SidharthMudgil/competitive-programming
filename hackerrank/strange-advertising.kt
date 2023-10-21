// USER: SIDHARTH MUDGIL
// DATE: Saturday 21, Oct 2023
// PROBLEM: Strange Advertising

fun viralAdvertising(n: Int): Int {
    var res = 0
    var people = 5
    repeat(n) {
        res += people / 2
        people = (people / 2) * 3
    }
    return res
}