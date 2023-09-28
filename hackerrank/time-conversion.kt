// USER: SIDHARTH MUDGIL
// DATE: Thursday 28, Sep 2023
// TASK: Time Conversion

fun timeConversion(s: String): String {
    val period = s[8].toString()
    var hour = s.substring(0 ..< 2).toInt()
    var min = s.substring(3 ..< 5).toInt()
    var sec = s.substring(6 ..< 8).toInt()
    
    when {
        hour < 12 && period.equals("P") -> hour += 12
        period.equals("P") && min == 0 && sec == 0 -> hour += 12
        hour == 12 && period.equals("A") -> hour = 0
           
    }
    val f = DecimalFormat("00")
    return "${f.format(hour)}:${f.format(min)}:${f.format(sec)}"
}
