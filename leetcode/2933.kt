// USER: SIDHARTH MUDGIL
// DATE: Sunday 07, Jan 2024
// PROBLEM: 2933. High-Access Employees

class Solution {
    fun String.toMinutes(): Int {
        val hrs = substring(0, 2).toInt()
        val min = substring(2, 4).toInt()
        return hrs * 60 + min
    }

    fun findHighAccessEmployees(access_times: List<List<String>>): List<String> {
        val map = mutableMapOf<String, MutableList<Int>>()
        val res = mutableListOf<String>()

        access_times.forEach {
            val name = it[0]
            map[name] = map.getOrDefault(name, mutableListOf()).apply{ add(it[1].toMinutes()) }
        }   

        map.forEach {
            val times = it.value.sorted()
            var cnt = 1
            var curr = times[0]

            for (i in 2 until times.size) {
                if (times[i] - curr < 60) {
                    res.add(it.key)
                    break
                }
                curr = times[i - 1]
            }
        }

        return res
    }
}