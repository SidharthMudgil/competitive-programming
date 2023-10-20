// USER: SIDHARTH MUDGIL
// DATE: Friday 20, Oct 2023
// PROBLEM: Counting Valleys

fun countingValleys(steps: Int, path: String): Int {
    var level = 0
    var valleys = 0

    path.forEach {
        when(it) {
            'D' -> level--
            'U' -> level++
        }
        
        if (it == 'U' && level == 0) {
            valleys++
        }
    }
    
    return valleys
}