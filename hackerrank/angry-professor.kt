// USER: SIDHARTH MUDGIL
// DATE: Friday 20, Oct 2023
// PROBLEM: Angry Professor

fun angryProfessor(k: Int, a: Array<Int>): String {
    a.sort()    
    return when {
        a[k - 1] > 0 -> "YES"
        else -> "NO"
    }
}

fun angryProfessor(k: Int, a: Array<Int>): String {
    var late = 0
    
    a.sortedDescending().forEach {
        if (it <= 0) {
            return@forEach
        }
        late++
    }
    
    if (a.size - late < k) {
        return "YES"
    } else {
        return "NO"
    }
}