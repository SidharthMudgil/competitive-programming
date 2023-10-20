// USER: SIDHARTH MUDGIL
// DATE: Friday 20, Oct 2023
// PROBLEM: Counting Valleys

fun countingValleys(steps: Int, path: String): Int {
    var level = 0
    var prev = 0
    var valleys = 0

    path.forEach {
        when(it) {
            'D' -> level--
            'U' -> level++
        }
        
        if (prev == 0 && level == -1) {
            valleys++
        }
        
        prev = level
    }
    
    return valleys
}