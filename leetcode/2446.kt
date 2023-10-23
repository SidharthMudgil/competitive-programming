// USER: SIDHARTH MUDGIL
// DATE: Monday 23, Oct 2023
// PROBLEM: 2446. Determine if Two Events Have Conflict

class Solution {
    fun haveConflict(event1: Array<String>, event2: Array<String>): Boolean {
        val e1s = event1[0].replace(":", ".").toDouble()
        val e1e = event1[1].replace(":", ".").toDouble()
        val e2s = event2[0].replace(":", ".").toDouble()
        val e2e = event2[1].replace(":", ".").toDouble()

        return when{
            e2s >= e1s && e2s <= e1e -> true
            e2e >= e1s && e2e <= e1e -> true
            e1s >= e2s && e1s <= e2e -> true
            e1e >= e2s && e1e <= e2e -> true
            else -> false
        }
    }
}