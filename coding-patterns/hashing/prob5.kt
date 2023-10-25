// USER: SIDHARTH MUDGIL
// DATE: Tuesday 24, Oct 2023
// PROBLEM: Find out the pair from array whose sum forms the number 'x' when both the numbers of the pair are added

fun hasPairs(arr: IntArray, x: Int): String {
    val s = mutableSetOf<Int>()
		
    arr.forEach {
        if (x - it in s) return "YES"
		s.add(it)
    }
    
    return "NO"
}