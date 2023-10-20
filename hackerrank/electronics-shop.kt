// USER: SIDHARTH MUDGIL
// DATE: Friday 20, Oct 2023
// PROBLEM: Electronic Shop

fun getMoneySpent(keyboards: Array<Int>, drives: Array<Int>, b: Int): Int {
    keyboards.sort()
    drives.sortDescending()
    var cost = -1
    
    keyboards.forEach { k ->
        drives.forEach { d -> 
            val t = k + d
            if (t > cost && t <= b) {
                cost = t
                return@forEach
            }
        }
    }
    
    return cost
}