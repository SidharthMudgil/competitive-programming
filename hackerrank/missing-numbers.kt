// USER: SIDHARTH MUDGIL
// DATE: Saturday 21, Oct 2023
// PROBLEM: Missing Numbers

fun missingNumbers(arr: Array<Int>, brr: Array<Int>): Array<Int> {
    val map = brr.groupBy { it }.mapValues { it.value.size }.toMutableMap()

    arr.forEach {
        if (map[it] != null) {
            map[it] = map[it]!! - 1
        }
    }
    
    val res = mutableListOf<Int>()

    map.forEach{ i, v ->
        res.addAll(List(v){i})
    }

    return res.sorted().toTypedArray()
}