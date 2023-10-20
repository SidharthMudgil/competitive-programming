// USER: SIDHARTH MUDGIL
// DATE: Friday 20, Oct 2023
// PROBLEM: The Hurdle Race

fun hurdleRace(k: Int, height: Array<Int>): Int {
    var max = 0
    
    height.forEach {
        if (it > max) {
            max = it
        }
    }
    
    return maxOf(0, max - k)
}
