// USER: SIDHARTH MUDGIL
// DATE: Tuesday 26, Dec 2023
// PROBLEM: Meeting Assistant

fun getEarliestMeetTime(events: Array<String>, k: Int): String {
    val map = IntArray(1440){0}
    
    events.forEach {
        val tokens = it.split(" ")
        val start = tokens[2].split(":")
        val end = tokens[3].split(":")
        
        val s = start[0].toInt() * 60 + start[1].toInt()
		val e = end[0].toInt() * 60 + end[1].toInt()
        
        
        map[s]++
        map[e + 1]--
    }
    
    var res = -1
    
    if (map[0] == 0) {
        res++
    }
    
    for (i in 1 until map.size) {
        map[i] = map[i] + map[i - 1]
        
        if (map[i] == 0) {
            res++
        }
        
        if (res == k) {
            res = i - k
            break
        }
    }
    
    return when(res) {
        -1 -> "-1"
        else -> "%02d:%02d".format((res / 60).toInt(), res % 60)
    }
}