// USER: SIDHARTH MUDGIL
// DATE: Saturday 21, Oct 2023
// PROBLEM: Cut the Sticks

fun cutTheSticks(arr: Array<Int>): Array<Int> {
    val res = mutableListOf<Int>()
    var li = arr.toMutableList()
    
    while (li.size > 0) {
        val min = li.min()
        res.add(li.size)
        li = li.filterNot{ it == min }.toMutableList()
        li.forEachIndexed { i, v ->
            li[i] = v - min
        }
    }

    return res.toTypedArray()
}